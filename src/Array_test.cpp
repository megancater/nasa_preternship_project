// Author: Drew A. Curtin
// Email: dcurtin@nd.edu
// 
// Pretern Project, Testing Ground for Array class.

// Libraries Included
#include "../inc/Array.h"

// Main
int main(){

    Array<int> Drew(5);

    Drew[0] = 25;

    std::cout << Drew;

    Array<int> Werd;

    Werd = Drew;

    std::cout << Werd;

    Drew.at(2) = 1;
    Werd.at(3) = 22;
    
    std::cout << Drew;
    std::cout << Werd;

    Array<char> Letters(12);

    Letters.fill('H');

    std::cout << Letters;

    Drew.at(22) = 444;

    return 0;
}