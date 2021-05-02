# Authors: Megan Cater, Drew Curtin, Mason Porter, Francesca Schena
# E-mails: mcater@nd.eda, dcurtin@nd.edu, mporter5@nd.edu, fschena@nd.edu
#
# This is the Makefile for the NASA Preternship Project

# Compilers and flags
PP := g++
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
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

