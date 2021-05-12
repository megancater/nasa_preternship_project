#include "../inc/algorithm.h"

/* Inserts data from text file stream into specified text file
 * Returns success, failure, or switch status */
int insert_data(Array<bool>& ValidDS,STRING& text_file, bool isconstant, int data_structure, long unsigned int memorydata) {

	// Returns instantly if previous recursive calls returned -1 (error)
	if (data_structure == -1) {
		return data_structure;
	}

 	// Data structure objects
	int i;                                    	// Iteration variable
	int elements = count_data(text_file);    	// Calculation
  	HashTable<float, int> hash(elements/5);		// Hash Table
  	float *arr = new float[elements];		// Array
	for(i=0;i<elements;i++) arr[i] = 0.0;		// Array initialization
  	DLL<float> dll;					// Doubly-Linked List
  	int old_structure=data_structure;		// For recursion purposes: If switch_data_structure is called, insert 
							// won't print data strucutre ( because it was switched via recursion )
	
 	 // Opens text file and creates input stream
	IFSTREAM input (text_file);

	// Checks that the file has opened successfully before entering data
	if (input.is_open()) {

		STRING line;				// Line to read file stream
		int count = 0;				// Counts amount of data read in ( counts lines since one data entry per line )

		// Prints message of insertion
		if (data_structure == dllist) {
			COUT << "Inserting data into doubly linked list..." << ENDL;
		}
		else if (data_structure == array) {
			COUT << "Inserting data into array..." << ENDL;
		}
		else {
			COUT << "Inserting data into hash table..." << ENDL;
		}

		// Reads data until EOF is reached or until the end is signalled
		while (GETLINE(input, line)) {
			// Converts string line of input to float
			float data = STOF(line);

			// Inserts data into doubly linked list
			if (data_structure == dllist) {
				dll.Insert(data);
			}

			// Inserts data into array
			else if (data_structure == array) {
        			arr[count] = data;
			}

			// Inserts data into hash table as pair
			else {
				PAIR<float, int> p(data, 1);
				hash.insert(p);
			}

			// Checks if memory threshold has been exceeded
      			if (determine_total_memory(count, data_structure, (int) hash.getCapacity()) > memorydata) {
				data_structure = switch_data_structure(ValidDS,data_structure, memorydata, isconstant, text_file);
				break;
			}

			count++;
		}

		delete [] arr; // deallocates array
	}

	// If the file has not opened successfully
	else {
		return -1;
	}
	
	// If current execution of insert_data() hasn't called a recursive loop of switch_data_structure(), print data structure
  	if(old_structure == data_structure){
 		if(data_structure == hashtable){
    			COUT << hash << ENDL;
  		}
		else if(data_structure == array){ 		// Manually written output function
			int c = 0;				// `c` keeps track of insertions on the current row
			for(i=0;i<elements;i++){
				c++;
				COUT << "# " << std::setw(4) << i << ": " << std::setw(4) << (int)arr[i] << " ";
				if(c==5){			// If entries on row = 5, create new row
					c = 0;
					COUT << " #" << ENDL;
				}
			}
			if (c != 0) COUT << "#";		// If data insertion doesn't end on a new line, add a `#` to the end
			COUT << ENDL;
  		}
		else if(data_structure == dllist){
    			COUT << dll << ENDL;
  		}
  	}

  	// Data has been inserted successfully
	return data_structure;
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

/* Checks if the data file has more duplicates than the `threshold` allows using a built-in R-B Tree */
bool duplicate_check(std::ifstream &infile, const float threshold){
	int          num, dupes=0;			// `num`: current value of insertion ; `dupes`: total number of duplicate values
	float        total=0;				// Total insertions (count_data() copy, but also tallied internally in this function
	MAP<int,int> countMap;				// R-B Tree to keep track of data with log(n) complexity searches

	PAIR< MAP<int,int>::iterator,bool > ret;	// R-B Tree iterator

  	// Read input from file and add values to map
  	while(infile >> num){
		total++;
    		ret = countMap.insert ( PAIR<int,int>(num,1) );
    		if (ret.second==false) {		// If the current `num` value is already in the `countMap`, then it is a duplicate
      			ret.first->second++;		// Interally keeps track of how many of each value have been inserted
      			dupes++;
    		}
  	}

	return (dupes >= total*threshold);		// Return True if duplicates are under given threshold; False otherwise
}

/* Function to determine the total memory taken up by the data once placed into the designated data structure */
long unsigned int determine_total_memory(int count, int data_structure, int number_buckets) {

	// All keys are floats and all values are integers
	long unsigned int key = sizeof(float);
	long unsigned int value = sizeof(int);

	// Pointers use 8 bytes of memory
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
int switch_data_structure(Array<bool>& ValidDS, int current_data_structure, long unsigned int memory_data, bool isConstant, STRING& text_file) {

	ValidDS.at(current_data_structure) = false;

	if(isConstant == false){
		ValidDS.at(array) = false;
	}
	else{
		ValidDS.at(dllist) = false;
	}

	int answer = checkValid(ValidDS, isConstant, text_file, memory_data);
	return answer;
}

/* Checks to make sure that only ONE data strucutre is determined to be optimal */
int checkValid(Array<bool>& ValidDSArray, bool isConstant, STRING& text_file, const long unsigned int memory_data) {

	int numWins = 0;		// Total number of 'optimal' data structures, should only return 1 if working properly
	int optimus = -1; 		// enumerated index of optimal data structure

	for( unsigned int i = 0; i < ValidDSArray.getSize(); i++ ){
		if(ValidDSArray.at(i) == true){
			numWins++;
			optimus = i;
		}
	}

	if(numWins == 1){
		insert_data(ValidDSArray,text_file, isConstant, optimus, memory_data);
		return optimus;
	}
	else{				// If this is reached, the program is running incorrectly
		std::cout << "No sufficient replacement, memory usage of unreasonable size." << std::endl;
		exit(-1);
	}
}
