// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
// $g++ -std=c++11 nullptr_vs_NULL.cpp 
//
#include <iostream>
//
// Nearly everyone illustrates passing address of a local variable into a function
// to modify that variable with...
// a pair of functions that swap the values in two variables
//
void swap1 (int left, int right)
{

    int temp = left;

    left = right;

    right = temp;

}

void swap2 (int *p_left, int *p_right)
{

    int temp = *p_left;

    *p_left = *p_right;

    *p_right = temp;

}

int main()
{

    int x = 1;

    int y = 2;

    swap1(x,y);
    
    std::cout << "Swapping by passing variables... \n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

    swap2( &x, &y );

    std::cout << "Swapping by passing addresses... \n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

}
