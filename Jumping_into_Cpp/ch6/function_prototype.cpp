// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Declaration tells the compiler how to use the function
//
int add (int x, int y);

int main()
{
    int result = add(1,7);

    std::cout << "The result is: " << result << std::endl;
    std::cout << "Using add() to add 3 and 4 gives: " << add(3,4) << std::endl;
}

//
// Defition
//
int add(int x, int y)
{
    return x + y;
}
