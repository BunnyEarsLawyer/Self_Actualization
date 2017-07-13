// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

int main()
{

    int x = 5;

    int *p_pointer_to_integer = & x;

    //
    // Prints a different address every time
    //

    std::cout << "Address of x from p  " <<  p_pointer_to_integer  << std::endl;

    //
    // The * is like the tip of a star that 'dereferences the pointer' 
    // It unravels the contents of the pointer points 
    // You are taking the reference to something and unraveling it. 
    // This always prints 5
    //

    std::cout << "Content of x from *p " <<  *p_pointer_to_integer << std::endl;

}
