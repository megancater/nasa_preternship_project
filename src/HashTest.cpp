#include <iostream>
#include <cstdlib>
#include "../include/HashTable.h"

#define COUT std::cout
#define ENDL std::endl

int main( int argc, char** argv ){
  int value;
  std::string key;
  FILE *stream = fopen("../input.txt","w+");
	if( argc < 2 ){

		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);

	}

	HashTable< std::string, int > the_LP_Hash;

	for( int iter = 1; iter < argc; ++iter ){

    key = argv[iter];
    if(iter+1 < argc){
		    value = atoi(argv[iter+1]);
    } else value = iter;



		the_LP_Hash.insert( { key, value } );


	}


    fscanf(stream,"%s %i",key,&value);
    the_LP_Hash.insert( { key, value } );

	COUT << "Linear Probe Hash:" << ENDL;
	COUT << the_LP_Hash << ENDL;

	return 0;
}
