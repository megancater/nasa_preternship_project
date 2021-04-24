#include "../inc/algorithm.h"

/* Inserts data from text file stream into specified text file
 * Returns true if data was entered successfully and false if memory threshold is exceeded */
bool insert_data(IFSTREAM& input, bool isconstant, int data_structure, const long unsigned int memorydata) {
	STRING line;
	int count = 0;

	// Data structure objects
	DLL dll;
	float arr[___];
	HashTable hash;

	// Amount of data is not changing
	if (isconstant) {
		// Reads data until EOF is reached
		while (GETLINE(input, line)) {
			// Converts string line of input to float
			float data = STOF(line);

			count++;
			
			// Inserts data into doubly linked list
			if (data_structure == dllist) {
				dll.insert(data);
			}

			// Inserts data into array
			if (data_structure == array) {
				// ?
			}

			// Inserts data into hash table
			if (data_structure == hashtable) {
				hash.insert(__);
			}

			// Checks if memory threshold has been exceeded
			if (determine_total_memory(count, data_structure) > memorydata) {
				switch_data_structure(data_structure);
			}
		}
	}

	return true;
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
