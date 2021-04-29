#include <iostream>
#include <fstream>
#include <string>
#include <map>

// NOTE: This part of the code MUST be compiled with the 2011 standard. the
// 1998 standard doesn't allow things like auto and range-based iteration

int duplicate_count(std::ifstream &infile){
  int num,dupes=0,total=0;
  std::map<int,int> countMap;

  std::pair<std::map<int,int>::iterator,bool> ret;

  // Read input from file and add values to map
  while(infile >> num){
    total++;
    ret = countMap.insert ( std::pair<char,int>(num,1) );
    if (ret.second==false) {
      ret.first->second++;
      dupes++;
    }
  }

  // Print Values and the number of duplicates/entries
  std::cout << "Items Tallied:" << std::endl;
  for (auto const &pair: countMap) {
    std::cout << pair.first << ": " << pair.second << "\n";
  }
  std::cout << dupes << " out of " << total << " entries were duplicates.\n";

  return dupes;
}

int main(){
  int dupes;
  std::ifstream infile("dupes.txt");

  dupe_threshold = duplicate_count(infile);
  std::cout << "Duplicate Threshold = " << dupe_threshold << std::endl;

  return 0;
}
