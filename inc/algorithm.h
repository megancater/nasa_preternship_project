#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>

#include "DLL.h"
#include "Hash_Table.h"
#include "Array.h"

#define IFSTREAM std::ifstream
#define OSTREAM std::ostream
#define CIN std::cin
#define COUT std::cout
#define ENDL std::endl
#define STRING std::string
#define GETLINE std::getline
#define STOF std::stof
#define PAIR std::pair
#define MAP std::map

/* Data structures enumerated list */
enum Data_Structure { dllist, array, hashtable };

/* Input data structure exit status list */
enum Insert_Exit { success, fail, switch_structure };


/* Inserts data from text file stream into specified text file
 * Returns success, failure, or switch status */
int insert_data(STRING& text_file, bool isconstant, int data_structure, long unsigned int memorydata);

/* Counts the amount of data in the given text file to determine the array size */
int count_data(STRING& text_file);

/* Switches to a more optimal data structure */
int switch_data_structure(int current_data_structure, long unsigned int memorydata, bool isConstant, STRING& txt_File );

int checkValid(Array<bool> ValidDSArray, bool isConstant, STRING& text_file, const long unsigned int memory_data);

/* Determines the overall memory taken up by the data structure with points loaded in */
long unsigned int determine_total_memory(int count, int data_structure, int number_buckets);

/* Determines the number of duplicates from data in text file */
bool duplicate_check(IFSTREAM &infile,const float threshold);

#endif
