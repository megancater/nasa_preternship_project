# Folder Variable Names

# Authors: Megan Cater, Drew Curtin, Mason Porter, Francesca Schena
# E-mails: mcater@nd.eda, dcurtin@nd.edu, mporter5@nd.edu, fschena@nd.edu
#
# This is the Makefile for the NASA Preternship Project

# Compilers and flags
PP := g++
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Folders
INC := inc
SRC := src
OBJ := obj
EXE := exe

# Command: make algorithm

# Command: make initialize
initialize:
	mkdir $(OBJ) $(EXE)

# Command: make clean
clean:
	rm -rf *.o $(OBJ)/* $(EXE)/* 
  
CarbonHash: $(OBJ)/CarbonHash.o
	$(PP) $(CXXFLAGS) -o $(EXE)/CarbonHash $^

$(OBJ)/CarbonHash.o: $(SRC)/CarbonHash.cpp
	$(PP) $(CXXFLAGS) -c $< -o $@

WeatherHash: $(OBJ)/WeatherHash.o
	$(PP) $(CXXFLAGS) -o $(EXE)/WeatherHash $^

$(OBJ)/WeatherHash.o: $(SRC)/WeatherHash.cpp
	$(PP) $(CXXFLAGS) -c $< -o $@


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
	
## Compile the Algorithm
# Initial Algorithm
$(OBJ)/algorithm.o: $(SRC)/algorithm.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/algorithm.cpp -o $@
	
# Object List
algorithm_test_objs := $(OBJ)/algorithm.o 

# Executable
algorithm_test: $(algorithm_test_objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/algorithm_test $(algorithm_test_objs)
