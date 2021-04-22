# Author: Drew A. Curtin
# Email: dcurtin@nd.edu
# 
# Pretern Project, Makefile for implemented data structure Array

## Basic Commands and Folders ##

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Folder Variable Names
INC := inc
SRC := src
OBJ := obj
EXE := exe

# Initialize
initialize:
	mkdir $(OBJ) $(EXE)
	
# Clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*

## Makefile with Array Class ##
# Command: make Array_test

# Initial Array_test
$(OBJ)/Array_test.o: $(SRC)/Array_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Array_test.cpp -o $@
	
# Object List
Array_test_objs := $(OBJ)/Array_test.o 

# Executable
Array_test: $(Array_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Array_test $(Array_test_objs)
