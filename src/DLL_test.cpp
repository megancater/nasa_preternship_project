// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
// 
// Pretern Project, Testing Ground for DLL class.

// Libraries Included
#include "../inc/DLL.h"

// Main
int main(){

    DLL<int> Drew;

    Drew.Insert(5);
    Drew.Insert(12);
    Drew.Insert(7);

    Drew.Delete(1);

    std::cout << Drew << std::endl;

    return 0;
}