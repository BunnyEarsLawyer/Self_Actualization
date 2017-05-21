// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

int DoStuff()
{
    return 2 + 5;
}

//
// Global variables can be initialized just like other variables 
//

int count_of_function_calls = 0;

//
// The scope of count_of_function_calls starts after DoStuff() 
// but before the fun() and main() functions 
//

void fun()
{
    count_of_function_calls++;
}


int main()
{
    fun();
    fun();
    fun();

    std::cout << count_of_function_calls << std::endl;

}
