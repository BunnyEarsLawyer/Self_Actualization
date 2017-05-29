// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

int add_two_numbers( int a, int b)
{
    return a+b;
}

int main()
{

    std::cout << "Adding 1 + 1: " << std::endl;

    int result = add_two_numbers(1,1);

    std::cout << result << std::endl;

}
