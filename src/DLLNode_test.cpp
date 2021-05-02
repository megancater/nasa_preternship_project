// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
// 
// Pretern Project, Testing Ground for DLLNode Struct.

// Libraries Included
#include "../inc/DLLNode.h"

// Main
int main(){

    DLLNode<int> Drew(1);

    std::cout << Drew.data << std::endl;

    return 0;
}