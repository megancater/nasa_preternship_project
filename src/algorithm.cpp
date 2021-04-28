#include "../inc/algorithm.h"

/* Inserts data from text file stream into specified text file
 * Returns true if data was entered successfully and false if memory threshold is exceeded */
int insert_data(STRING& text_file, bool isconstant, int data_structure, const long unsigned int memorydata) {
	// Opens text file and creates input stream
	IFSTREAM input (text_file);

	// Checks that the file has opened successfully before entering data
	if (input.is_open()) {
		STRING line;
		int count = 0;

		// Data structure objects
		DLL dll;
		float arr[count_data(text_file)];
		HashTable hash;

		// Reads data until EOF is reached or until the end is signalled
		while ((isconstant  || (!isconstant && !end_signal)) && GETLINE(input, line)) {
			// Converts string line of input to float
			float data = STOF(line);
			
			// Inserts data into doubly linked list
			if (data_structure == dllist) {
				dll.insert(data);
			}

			// Inserts data into array
			if (data_structure == array) {
				arr[count] = data;
			}

			// Inserts data into hash table
			if (data_structure == hashtable) {
				hash.insert(data);
			}

			// Checks if memory threshold has been exceeded
			if (determine_total_memory(count, data_structure) > memorydata) {
				return switch_structure;
			}

			count++;
		}
	}

	// If the file has not opened successfully
	else {
		return fail;
	}

	// Data has been inserted successfully
	return success;
}

/* Counts the amount of data in the given text file to determine the array size */
int count_data(STRING& text_file) {
	STRING line;
	int count = 0;

	// Opens text file and creates input stream
	IFSTREAM input (text_file);

	// Increments count for each line in the text file
	while (GETLINE(input, line)) {
		count++;
	}

	return count;
}

/* Switches to a more optimal data structure */
void switch_data_structure(int current_data_structure) {
	return NULL;
}

/* Checks if number of duplicates in the text file exceeds the duplicate threshold */
int run_duplicate_check(OFSTREAM& stream, int duplicate_threshold) {
	return 0;
}

/* Determines the total amount of memory the data structure will take up */
long unsigned int determine_total_memory(int count, int data_structure) {
	return 0;
}
