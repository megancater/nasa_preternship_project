#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "../include/HashTable.h"

#define COUT std::cout
#define ENDL std::endl

// CarbonHash.cpp
// Mason Porter
// Takes in data outputted from the carbon.py program and inserts
// into a hash table. This isn't really useful considering that
// the results from carbon.py will be in order anyway, so it's
// likely the algorithm we make will never recommend putting that
// data into a hash table anyway.

int main( int argc, char** argv ){
  int value, day = 1, week =1, n = 0, in = 0, div = 1;
  // Day & Week: values used to generate key string
  // n:   Once n >= a random number, a pair will be inserted
  // in:  tracks number of insertions (for performance,
  //      hash table is increasingly slower with more inputs)
  // Div: The estimated amount of values we'll receive from the
  //      file until one is inserted into the hash
  std::string key;

  if( argc < 2 ){
		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);
	}

  std::ifstream infile(argv[1]);

	HashTable< std::string, int > hash;
  srand((unsigned) time(0));
  int rand_num = (rand() % div) + 1;

	while(infile >> value && in < 250){

    key = "Week " + std::to_string(week) + " Day " + std::to_string(day++);

    if(n >= rand_num){
		    hash.insert( { key, value } );
        n = 0; in++;
        rand_num = (rand() % 5) + 1;
    } else n++;

    if(day > 7){
      week++;
      day = 1;
    }
	}

	COUT << "Carbon Hash:" << ENDL;
	COUT << hash << ENDL;

	return 0;
}
