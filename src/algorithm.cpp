#include "../inc/algorithm.h"

// CREATE OBJECT

/* Inserts data from text file stream into specified text file
 * Returns true if data was entered successfully and false if memory threshold is exceeded */
int insert_data(STRING& text_file, bool isconstant, int data_structure, const long unsigned int memorydata) {
	// Opens text file and creates input stream
	IFSTREAM input;
	
	input.open(text_file, IFSTREAM);

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

int duplicate_count(std::ifstream &infile){
	int num,dupes=0,total=0;
	std::map<int,int> countMap;

	std::pair< std::map<int,int>::iterator,bool > ret;

  	// Read input from file and add values to map
  	while(infile >> num){
		total++;
    	ret = countMap.insert ( std::pair<char,int>(num,1) );
    	if (ret.second==false) {
      		ret.first->second++;
      		dupes++;
    	}
  	}

  	// Print Values and the number of duplicates/entries
  	std::cout << "Items Tallied:" << std::endl;
  	for (auto const &pair: countMap) {
		std::cout << pair.first << ": " << pair.second << "\n";
  	}
  	//std::cout << dupes << " out of " << total << " entries were duplicates.\n";

	return dupes;
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

	if(data_structure == hashmap) {
		return ((sizeof(key) + sizeof(value))*number_buckets);
	}

	else if(data_structure == dllist) {
		return (head + tail + (sizeof(float) + prev + next)*count;
	}

	else if(data_structure == array) {
		return (sizeof(float)*count);
	}
}

// Determines the most optimal data structure to switch to from those remaining
void switch_data_structure(int current_data_structure, unsigned int num_data_structures, int count, const long unsigned int memorydata, bool isConstant, STRING& text_file) {

	Array<bool> ValidDS(num_data_structures);         // An array (class) of bools to represent all     the data structures

	ValidDS.fill(true);                               // Initialize all data structures to be intially valid choices

	unsigned int validDS = 0;

	for( unsigned int i = 0; i < ValidDS.size(); i++ ){       	 // Initial memory check, upper bound of memory

		if( determine_total_memory(count, i) > memory_data ){    // Possibly times a constant? (0.8 * memory_data)

			ValidDS.at(i) = false;
		}
  	}

	if(isConstant == false){

		ValidDS.at(array) = false;
		checkValid(ValidDs);	  // Check number of data structures we have left and                    					make a decision...	
	}
	else{

		ValidDS.at(dll) = false;
		checkValid(ValidDs);								
	}

// FAILSAFE FOR HAVING MORE THAN ONE LEFT?	

	return NULL;
}

void checkValid(Array<bool> ValidDSArray) {

	int numWins = 0;
	int optimus = -1;

	for( unsigned int i = 0; i < ValidDSArray.size(); i++ ){

		if(ValidDSArray.at(i) == true){

			numWins +=;
			optimus = i;
		}
	}

	if(numWins == 1){
		
		insert_data(text_file, isConstant, optimus, memorydata);
	}
	else if(numWins == 0){

std::cout << "No sufficient replacement, memory usage of unreasonable size." << std::endl;
	}

}

