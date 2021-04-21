# Author: Drew A. Curtin
# Email: dcurtin@nd.edu
# 
# Pretern Project, Makefile for implemented data structures DLL and Array

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

## Makefile with DLLNode Class ##
# Command: make DLLnode_test

# Initial DLLNode_test
$(OBJ)/DLLNode_test.o: $(SRC)/DLLNode_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/DLLNode_test.cpp -o $@
	
# Object List
DLLNode_test_objs := $(OBJ)/DLLNode_test.o 

# Executable
DLLNode_test: $(DLLNode_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLLNode_test $(DLLNode_test_objs)

## Makefile with DLL Class ##
# Command: make DLL_test

# Initial DLL_test
$(OBJ)/DLL_test.o: $(SRC)/DLL_test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/DLL_test.cpp -o $@
	
# Object List
DLL_test_objs := $(OBJ)/DLL_test.o 

# Executable
DLL_test: $(DLL_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/DLL_test $(DLL_test_objs)