// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
//
// Pretern Project, Class Array.
#ifndef ARRAY_H
#define ARRAY_H

// Libraries Included
#include <cstdlib>
#include <iostream>

template< class T >
class Array{

    private:

        unsigned int size;
        T* data;

    public:

        // Default Constructor
        Array() : size(0), data( (T*) malloc(size * sizeof(T)) ) {}

        // Overloaded Constructor
        Array(const unsigned int& sizeIn) : size(sizeIn), data( (T*) malloc(size * sizeof(T)) ) {}

        // Destructor
        ~Array(){

            delete data;
        }

        // Copy Constructor
        Array(Array<T>& copy) : size(copy.size), data( (T*) malloc(size * sizeof(T)) ){

            for(unsigned int i = 0; i < size; i++){

                *(data + i) = copy[i];
            }

        }

        // Assignment Operator
        Array<T>& operator=(Array& rhs){

            if(this != &rhs){

                size = rhs.size;
                data = (T*) malloc(size * sizeof(T));

                for(unsigned int i = 0; i < size; i++){

                    *(data + i) = rhs[i];
                }
            }

            return *this;
        }

        // Method: begin()
        // Return 1st element in the array
        T& begin() const{

            return data[0];
        }

        // Method: end()
        // Return last element in the array
        T& end() const{

            return data[size - 1];
        }

        // Method: size()
        // Return the size of the array
        unsigned int getSize() const{

            return size;
        }

        // Method: at(value)
        // Essentially the [] operator but with error checking
        T& at(const unsigned int value) const{

            if (value >= size){

                std::cout << ".at() request is out of bounds..." << std::endl;
                exit(-1);
            }
            else{
                return *(data + value) = value;
            }
        }

        // Method: fill(value)
        // Fills array with the entered value
        void fill(const T& value){

            for(unsigned int i = 0; i < size; i++){

                *(data + i) = value;
            }
        }

        // Overloaded Operator []
        T& operator[](const unsigned int i){

            return *(data + i);
        }

        // Friend Operator
        friend std::ostream& operator<<(std::ostream& output, Array& theArray){

            for( unsigned int i = 0; i < theArray.size; i++){

                output << theArray[i] << " ";
            }

            output << std::endl;

            return output;
        }

};

#endif
