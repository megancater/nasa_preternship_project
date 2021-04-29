#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include "../inc/Array.h"

#define OFSTREAM std::ofstream
#define OSTREAM std::ostream
#define CIN std::cin
#define COUT std::cout

// Ennumerated Type DS to be used in function
enum DS { dllist, array, hashmap};

/* Inserts data from text file stream into specified text file
 * Returns true if data was entered successfully and false if memory threshold is exceeded */
bool insert_data(OFSTREAM& stream, bool isconstant, int data_structure, const long unsigned int memorydata);

/* Switches to a more optimal data structure */
void switch_data_structure(int current_data_structure, unsigned int num_data_structures, int count, const unsigned int memorydata, bool isConstant, STRING& );

void checkValid(Array<bool> ValidDSArray);

/* Checks if number of duplicates in the text file exceeds the duplicate threshold */
int run_duplicate_check(OFSTREAM& stream, int duplicate_threshold);

/* Determines the total amount of memory the data structure will take up */
long unsigned int determine_total_memory(int count, int data_structure);

#endif ALGORITHM_H