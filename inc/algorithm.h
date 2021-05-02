#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

#include "DLL.h"
#include "Hash_Table.h"

#define IFSTREAM std::ifstream
#define OSTREAM std::ostream
#define CIN std::cin
#define COUT std::cout
#define STRING std::string
#define GETLINE std::getline
#define STOF std::stof

/* Data structures enumerated list */
enum Data_Structure { dllist, array, hashtable };

/* Input data structure exit status list */
enum Insert_Exit { success, fail, switch_structure };


/* Inserts data from text file stream into specified text file
 * Returns true if data was entered successfully and false if memory threshold is exceeded */
int insert_data(STRING& text_file, bool isconstant, int data_structure, const long unsigned int memorydata);

/* Counts the amount of data in the given text file to determine the array size */
int count_data(STRING& text_file);

/* Switches to a more optimal data structure */
void switch_data_structure(int current_data_structure);

/* Checks if number of duplicates in the text file exceeds the duplicate threshold */
int run_duplicate_check(OFSTREAM& stream, int duplicate_threshold);

/* Determines the total amount of memory the data structure will take up */
long unsigned int determine_total_memory(int count, int data_structure);

#endif
