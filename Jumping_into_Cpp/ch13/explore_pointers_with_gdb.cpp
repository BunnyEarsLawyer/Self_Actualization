// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

int main()
{

    int x;

    int *p_int;
    
    p_int = & x;
  
    *p_int = 5;
    
    std::cout << "Dereferencing pointer *p_int ... \n " <<  *p_int << "\n";

    *p_int = 10;

    std::cout << "Used pointer to change value of x ... \n" 
              << "*p_int = 10; \n" 
              << x << "\n"; 

}
