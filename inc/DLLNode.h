// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
// 
// Pretern Project, Node Struct for DLL.
#ifndef DLLNODE_H
#define DLLNODE_H

// Libraries
#include <iostream>

// DLL NODE STRUCT BELOW //
template< class T >
struct DLLNode{

    // Members //
    T data;
    DLLNode* next;
    DLLNode* prev;

    // Methods // 
    // Default Constructor
    DLLNode() : data(), next(NULL), prev(NULL) {}

    // Overloaded Constructor
    DLLNode(const T& dataIn) : data(dataIn), next(NULL), prev(NULL) {}

    // Destructor - Recursive Deletion
    ~DLLNode() {

        delete next;
    }

    // Copy Constructor - Only want to copy the data or else we mess up the list...
    DLLNode(const DLLNode<T>& copy) : data(copy.data), next(NULL), prev(NULL) {}

    // Assignment Operator, again, don't want to set prev or next...
    DLLNode<T> operator=(const DLLNode<T>& rhs) {

        if (this != &rhs){

            this->data = rhs.data;
            this->next = NULL;
            this->prev = NULL;
        }

        return *this;
    }

    // Not Equal Operator
    bool operator!=(const DLLNode<T>& rhs) {

        return *this != rhs;
    }

    // Assignment Operator for DLLNode Pointer
    DLLNode<T>* operator=(const DLLNode<T>* rhs){

        if (this != (void *)&rhs){

            this->data = rhs.data;
            this->next = rhs.next;
            this->prev = rhs.prev;
        }

        return *this;
    }

    // Node Not Equal Operator
    bool operator!=(const DLLNode<T>* rhs){

        return *this != (void *)rhs;
    }

};

#endif