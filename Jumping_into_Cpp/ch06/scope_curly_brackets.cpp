// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

int divide( int numerator, int denominator )
{
    if ( 0 == denominator )
    {

        int result = 0;

        return result; 

    }

    //
    // Compiler does not stop you from creating a variable with the same name
    // b/c they are not in the same SCOPE
    //

    int result = numerator / denominator;
    
    return result;

}

int main()
{
    int a = 12; //Try 3
    int b = 4;  //And 4 => divide(3,4) returns 0 !
    int c = 0;

    c = divide(a,b); 

    std::cout << c << std::endl; 

}
