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

//
// Notice this function does not swap anything!
// b/c the variables local   
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

//
// Using references instead of pointers
// This function will change the originals!
//
void swap3 (int& left, int& right)
{

    int temp = left;

    left = right;

    right = temp;

}

int main()
{

    int x = 1;

    int y = 2;

    std::cout << "Original content... \n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

    swap1(x,y);
    
    std::cout << "Swapping by passing variables (bad)...\n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

    swap2( &x, &y );

    std::cout << "Swapping by passing addresses... \n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

    swap3( x, y );

    std::cout << "Swapping by passing references... \n " 
              << "x: " << x << "\n"
              << "y: " << y << "\n";

}
