#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include "../inc/algorithm.h"


#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream
#define CIN std::cin
#define STRING std::string

int main(int argc, char** argv)
{
	bool array1 = true;
	bool dll = true;
	bool hashmap = true;
	bool duplicates;
	long int userdata;
	int result;
	const float threshold = 0.25;
	char *filename = argv[1];
	STRING file = argv[1];
  
  Array<bool> ValidDS(3);
  ValidDS.fill(true);

	std::ifstream infile(filename);

	bool isConstant = false;


	if(argc < 2 || argc > 2)
	{
		COUT << "Incorrect number of inputs." << ENDL;
		return 1;
	}

	// User Input
	
	COUT << "Welcome to your memory optimization software!" << ENDL;
	COUT << "" << ENDL;
	COUT << "Before we choose the best data structure for your data, we have a few questions." << ENDL;
	COUT << "Answers with Y for yes or N for no." << ENDL;
	// are we going to assume the user uses valid input?

	STRING yesupper = "Y";
	STRING yeslower = "y";
	STRING noupper = "N";
	STRING nolower = "n";

	STRING constant;
	STRING direct;
	STRING sort;


	// Questions
	
	// Determine memory allowed
	COUT << "How much memory does your environment allow? ";
	CIN >> userdata;


	COUT << "Is your data set constant? (Will your number of data points stay the same?) " ;
	CIN >> constant;

	if((constant.compare(yesupper) == 0) || (constant.compare(yeslower) == 0))
	{
		isConstant = true;
		dll = false;

		COUT << "Is direct access to your data needed? ";
		CIN >> direct;

		if((direct.compare(yesupper) == 0) || (direct.compare(yeslower) == 0))
		{
			hashmap = false; // leaves array as best choice
		}
		else if((direct.compare(noupper) == 0) || (direct.compare(nolower) == 0))
		{
			COUT << "Does your data need to stay in order? ";
			CIN >> sort;

			if((sort.compare(yesupper) == 0) || (sort.compare(yeslower) == 0))
			{
				hashmap = false; // leave array as best choice
			}
			else if((sort.compare(noupper) == 0) || (sort.compare(nolower) == 0))
			{
				duplicates = duplicate_check(infile,threshold);
				if(duplicates == true)
				{
					array1 = false; // leaves hash map as best choice
				}
				else if(duplicates == false)
				{
					hashmap = false; // leaves array as best choice
				}
			}
		}
	}
	else if((constant.compare(noupper) == 0) || (constant.compare(nolower) == 0))
	{
		array1 = false;

		COUT << "Does your data need to stay in order? ";
		CIN >> sort;

		if((sort.compare(yesupper) == 0) || (sort.compare(yeslower) == 0))
		{
			hashmap = false; // leave dll as best choice
		}
		else if((sort.compare(noupper) == 0) || (sort.compare(nolower) == 0))
		{
			duplicates = duplicate_check(infile,threshold);
			if(duplicates == true)
			{
				dll = false; // leaves hash map as best choice
			}
			else if(duplicates == false)
			{
				hashmap = false; // leaves dll as best choice
			}
		}

	}

	//Beginning of Algorithm Calls
	if(array1 == true)
	{
		result = insert_data(ValidDS,file,isConstant,array,userdata);
	}
	else if(dll == true)
	{
		result = insert_data(ValidDS,file,isConstant,dllist,userdata);
	}
	else if(hashmap == true)
	{
		result = insert_data(ValidDS,file,isConstant,hashtable,userdata);
	}

	
	//Output data to user!	
	if(result == hashtable)
	{
		COUT << "Hash Table is the most suitable data structure!" << ENDL;
	}

	else if(result == dllist)
	{
		COUT << "Doubly Linked List is the most suitable data structure!" << ENDL;
	}
	else if(result == array)
	{
		COUT << "Array is the most suitable data structure!" << ENDL;
	}

	return 0;

}
