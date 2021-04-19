# G++ is for the GCC compiler for C++
PP := g++

FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj

initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

clean :
	rm -rf $(OBJ)/* $(EXE)/*

CarbonHash: $(OBJ)/CarbonHash.o
	$(PP) $(CXXFLAGS) -o $(EXE)/CarbonHash $^

$(OBJ)/CarbonHash.o: $(SRC)/CarbonHash.cpp
	$(PP) $(CXXFLAGS) -c $< -o $@

WeatherHash: $(OBJ)/WeatherHash.o
	$(PP) $(CXXFLAGS) -o $(EXE)/WeatherHash $^

$(OBJ)/WeatherHash.o: $(SRC)/WeatherHash.cpp
	$(PP) $(CXXFLAGS) -c $< -o $@
