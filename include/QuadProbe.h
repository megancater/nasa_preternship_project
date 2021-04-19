#ifndef QUADPROBE_H
#define QUADPROBE_H

#include "LinearProbe.h"

template<class Key, class Value>
class QuadProbe : public HashTable<Key,Value>{

private:
  long unsigned int findPos( const Key& theKey ) const{

    long unsigned int cap = this->array.capacity();
    long unsigned int currentPos = this->HashFunc(theKey);
    long unsigned int lastPos = 0;
    long unsigned int iter = 0;
    const unsigned int STEPSIZE = 1;
    double c1,c2;
    do{
      // Hash Function determines current position
      c1 = 0.5*iter*STEPSIZE;
      c2 = 0.5*(iter*iter)*STEPSIZE;
      lastPos = currentPos;
      currentPos = (long unsigned int)((lastPos % cap)+c1+c2)%cap;
      ++iter;
    }
    while(
      this->array.at( currentPos ).state != EMPTY
      && this->array.at( currentPos ).state != DELETED
      && this->array.at( currentPos ).key != theKey
      && iter < this->array.capacity()
    );
    // Return capacity if the current value isn't the key. For safety
    if(this->array.at( currentPos ).state == ACTIVE
      && this->array.at( currentPos ).key != theKey ){
        return this->array.capacity();
      }
    return currentPos;
  }

public:
  QuadProbe() : HashTable<Key, Value>() {}

  ~QuadProbe() {}

  friend std::ostream& operator<<( std::ostream& output, const QuadProbe<Key, Value>& theTable ){

    output << "Hash Table Size: " << theTable.array.size() << std::endl;
    output << "Hashed Elements: " << theTable.numHash << std::endl;

    for(unsigned int iter = 0; iter < theTable.array.size(); iter++){

      output << "{" << iter << ": ";

      if( theTable.array[iter].state == ACTIVE ) output << "ACTIVE, ";
      else if( theTable.array[iter].state == DELETED ) output << "DELETED, ";
      else output << "EMPTY, ";

      output << theTable.array[iter].key << ", ";
      output << theTable.array[iter].value << "}" << std::endl;
    }
    return output;
  }

};

#endif
