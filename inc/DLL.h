// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
// 
// Pretern Project, Class DLL.
#ifndef DLL_H
#define DLL_H

// Libraries Included
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "../inc/DLLNode.h"

template< class T >
class DLL{

    private:

        DLLNode<T>* head;
        DLLNode<T>* tail;

    public:

    // Default Constructor
    DLL() : head(NULL), tail(NULL) {}

    // Destructor: Recursive Deletion
    ~DLL() {

        delete head;
    }

    // Copy Constructor
    DLL( const DLL<T>& copy ) : head(NULL), tail(NULL) {

        DLLNode<T>* curr = copy.head;

        while(curr != NULL){        

            Insert(curr->data);

            curr = curr->next;
        }
    }

    // Assignment Operator
    DLL<T>& operator=(const DLL<T>& rhs){

        if (this != rhs){

            DLLNode<T>* curr = rhs.head;

            while(curr != NULL){

                this->Insert(curr->data);

                curr = curr->next;
            }
        }

        return *this;
    }

    // Method: Insert
    // Creates a DLLNode with a value and inserts at end of the DLL
    void Insert(const T& value){

        DLLNode<T>* temp = new DLLNode<T>(value);

        if( IsEmpty() ){                   

            head = temp;
            tail = temp;
        }
        else{

            DLLNode<T>* prev = NULL;
            DLLNode<T>* curr = head;

            while (curr != NULL){           // Traverse to end

                prev = curr;
                curr = curr->next;
            }

            prev->next = temp;              // Insert temp at end

            prev->next->prev = prev;        // temp's previous point back to previous

            tail = prev->next;              // Update tail
        }
    }

    // Method: push_front
    // Puts value at the front of the DLL ( O(1) insert )
    void push_front(const T& value){

        if( IsEmpty() ){

            Insert(value);
        }
        else{

            DLLNode<T>* temp = new DLLNode<T>(value);

            temp->next = head;

            head->prev = temp;

            head = temp;
        }
    }

    // Method: push_back
    // Puts value at the back of the DLL ( O(1) insert )
    void push_back(const T& value){

        if( IsEmpty() ){

            Insert(value);
        }
        else{

            DLLNode<T>* temp = new DLLNode<T>(value);

            temp->prev = tail;

            tail->next = temp;

            tail = temp;
        }
    }

    // Method: Delete
    // Deletes the first of the specified value if in the DLL.  If not, return -1
    bool Delete(const T& value){

        DLLNode<T>* temp = new DLLNode<T>();
        DLLNode<T>* prev = new DLLNode<T>();
        DLLNode<T>* curr = new DLLNode<T>();

        if( IsEmpty() ){
            std::cout << "List is empty, can't delete..." << std::endl;
            return(-1);
        }
        else if(value == head->data){

            if(head == tail){
                
                temp = head;
                head = NULL;
                tail = NULL;

                free(temp);
                return true;
            }
            else{

                temp = head;
                head = head->next;
                head->prev = NULL;

                free(temp);
                return true;
            }
        }
        else{
        
            prev = head;
            curr = head->next;

            while(curr != NULL && curr->data != value){

                prev = curr;
                curr = curr->next;
            }

            if(curr != NULL){

                temp = curr;

                if(curr == tail){

                    tail = prev;
                }

                prev->next = curr->next;
                free(temp);

                if(prev->next != NULL){

                    prev->next->prev = prev;
                }

                return true;
            }
            else{
                std::cout << value  << " was not in the list..." << std::endl;
                return false;
            }

        }

    }

    // Method: IsEmpty
    // Basic Method, returns true if the DLL contains 0 values
    bool IsEmpty() const{

        return (head == NULL && tail == NULL);
    }

    // Method: Contains
    // Returns whether the value entered is in the DLL
    bool contains(const T& searchVal) const{

        if ( IsEmpty() ){

            return false;
        }
        else{

            DLLNode<T>* curr = head;

            while (curr != NULL && curr->data != searchVal){
                
                curr = curr->next;
            }

            return (curr != NULL);
        }
    }

    // Friend Operator: DLL Overloaded Ostream
    friend std::ostream& operator<<(std::ostream& output, const DLL<T>& theDLL){
        
        int i,dashes = 0;
        DLLNode<T>* curr;

        if( theDLL.IsEmpty() ){
            output << "The List is Empty";
        }
        else{

            curr = theDLL.head;
            dashes += 6;
            output << "HEAD: ";
            // output << "(" << dashes << ")";
            while(curr != NULL){

                output << (int)curr->data;
                dashes += (int)(log10(curr->data)+1);
                // output << "(" << dashes << ")";
                if(dashes  < 70){
                  if (curr->next != NULL) output << " -> ";
                  dashes += 4;
                  // output << "(" << dashes << ")";
                }
                else if (curr->next != NULL){
                 dashes -= 3;
                 output << std::endl << "  ";
                 for(i=0;i<dashes;i++) output << " ";
                 output << "|" << std::endl << " V";
                 for(i=0;i<dashes;i++) output << "-";
                 output << std::endl;
                 dashes = 0;
                }

                curr = curr->next;
            }

            output << std::endl;
        }

        return output;
    }

};

#endif
