#include "../inc/algorithm.h"

/* Inserts data from text file stream into specified text file
 * Returns success, failure, or switch status */
int insert_data(STRING& text_file, bool isconstant, int data_structure, const long int memorydata) {
	// Opens text file and creates input stream
	IFSTREAM input (text_file);

	// Checks that the file has opened successfully before entering data
	if (input.is_open()) {
		STRING line;
		int count = 0;

		// Data structure objects
		DLL<float> dll;
		float *arr = new float[count_data(text_file)];
		HashTable<float, int> hash;

		// Reads data until EOF is reached or until the end is signalled
		while ((isconstant  || (!isconstant && !end_signal)) && GETLINE(input, line)) {
			// Converts string line of input to float
			float data = STOF(line);

			// Inserts data into doubly linked list
			if (data_structure == dllist) {
				dll.Insert(data);
			}

			// Inserts data into array
			if (data_structure == array) {
				arr[count] = data;
			}

			// Inserts data into hash table as pair
			if (data_structure == hashtable) {
				PAIR<float, int> p(data, 1);

				hash.insert(p);
			}

			// Checks if memory threshold has been exceeded
			if (determine_total_memory(count, data_structure, (int) hash.getCapacity()) > (unsigned int) memorydata) {
				delete [] arr; // deallocates array

				return switch_structure;
			}

			count++;
		}

		delete [] arr; // deallocates array
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

bool duplicate_check(std::ifstream &infile, const float threshold){
	int          num, dupes=0;
	float        total=0;
	MAP<int,int> countMap;

	PAIR< MAP<int,int>::iterator,bool > ret;

  	// Read input from file and add values to map
  	while(infile >> num){
		total++;
    	ret = countMap.insert ( PAIR<char,int>(num,1) );
    	if (ret.second==false) {
      		ret.first->second++;
      		dupes++;
    	}
  	}

  	// Print Values and the number of duplicates/entries
  	COUT << "Items Tallied:" << ENDL;
  	for (auto const &pair: countMap) {
		COUT << pair.first << ": " << pair.second << "\n";
  	}
  	//std::cout << dupes << " out of " << total << " entries were duplicates.\n";

	return (dupes >= total*threshold);
}

/* Function to determine the total memory taken up by the data once placed into the designated data structure */
long unsigned int determine_total_memory(int count, int data_structure, int number_buckets) {

	/* All keys are floats and all values are integers */
	long unsigned int key = sizeof(float);
	long unsigned int value = sizeof(int);

	/* Pointers use 8 bytes of memory */
	long unsigned int head = 8;
	long unsigned int tail = 8;
	long unsigned int prev = 8;
	long unsigned int next = 8;

	if(data_structure == hashtable) {
		return ((sizeof(key) + sizeof(value))*number_buckets);
	}

	else if(data_structure == dllist) {
		return head + tail + (sizeof(float) + prev + next)*count;
	}

	else if(data_structure == array) {
		return (sizeof(float)*count);
	}
	
		return -1;
}

// Determines the most optimal data structure to switch to from those remaining
void switch_data_structure(int current_data_structure, unsigned int num_data_structures, const long unsigned int memory_data, bool isConstant, STRING& text_file) {

	Array<bool> ValidDS(num_data_structures);         // An array (class) of bools to represent all the data structures

	ValidDS.fill(true);                               // Initialize all data structures to be intially valid choices

	ValidDS.at(current_data_structure);

	if(isConstant == false){

		ValidDS.at(array) = false;
	}
	else{
		ValidDS.at(dllist) = false;
	}

	checkValid(ValidDS, isConstant, text_file, memory_data);
}

void checkValid(Array<bool> ValidDSArray, bool isConstant, STRING& text_file, const long unsigned int memory_data) {

	int numWins = 0;
	int optimus = -1;

	for( unsigned int i = 0; i < ValidDSArray.getSize(); i++ ){

		if(ValidDSArray.at(i) == true){

			numWins ++;
			optimus = i;
		}
	}

	if(numWins == 1){

		insert_data(text_file, isConstant, optimus, memory_data);
	}
	else if(numWins == 0){

		std::cout << "No sufficient replacement, memory usage of unreasonable size." << std::endl;
	}

}
