// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

void change_argument( int x )
{
    x = x + 5;
}

int main()
{
    int y = 4;

    change_argument(y);          // Y will be unharmed by the function call

    std::cout << y << std::endl; // still prints 4

}
