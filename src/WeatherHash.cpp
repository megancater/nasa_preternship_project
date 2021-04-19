#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../include/HashTable.h"

#define COUT std::cout
#define ENDL std::endl

// CarbonHash.cpp
// Mason Porter
// Takes in data outputted from my example weather text file
// and inserts it into hash table

int main( int argc, char** argv ){
  int value;
  std::string key,temp;

  if( argc < 2 ){
		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);
	}

  std::ifstream infile(argv[1]);

	HashTable< std::string, int > hash;

	while(infile){
    std::getline(infile,key,';');
    std::getline(infile,temp);
    value = std::stoi(temp);

		if(key!="") hash.insert( { key, value } );
  }

	COUT << "Weather Data:" << ENDL;
	COUT << hash << ENDL;

	return 0;
}
