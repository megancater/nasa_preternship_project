bool insert_data(OFSTREAM& stream, bool isconstant, int data_structure, const long unsigned int memorydata) {
	return true;
}

/* Switches to a more optimal data structure */
// My approach is thus: we first check memory limit, then run down the logic tree as far as we can
// without running out of data structures.  As soon as we hit 1 valid data structure remaining, we 
// pick that one.  This DS will thus reflect the memory limit and as many user input preferences as
// reasonablely possible, making it the "optimal" data structure.
void switch_data_structure(int current_data_structure, unsigned int num_data_structures, int count, const long unsigned int memorydata, 
						   bool isConstant, STRING& text_file) {

	Array<bool> ValidDS(num_data_structures);         // An array (class) of bools to represent all the data structures

	ValidDS.fill(true);                               // Initialize all data structures to be intially valid choices

	unsigned int validDS = 0;

	for( unsigned int i = 0; i < ValidDS.size(); i++ ){       	 // Initial memory check, upper bound of memory

    	if( determine_total_memory(count, i) > memory_data ){    // Possibly times a constant? (0.8 * memory_data)

			ValidDS.at(i) = false;
    	}
  	}

	if(isConstant == false){

		ValidDS.at(array) = false;
		checkValid(ValidDs);								// Check number of data structures we have left and make a decision...
		
	}
	else{

		ValidDS.at(dll) = false;
		checkValid(ValidDs);								// Check number of data structures we have left and make a decision...												
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

/* Checks if number of duplicates in the text file exceeds the duplicate threshold */
int run_duplicate_check(OFSTREAM& stream, int duplicate_threshold) {
	return 0;
}

/* Determines the total amount of memory the data structure will take up */
long unsigned int determine_total_memory(int count, int data_structure) {
	return 0;
}