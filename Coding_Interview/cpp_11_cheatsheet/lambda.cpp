// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <typeinfo>

int main()
{
    // If you need to store lambda you may use auto
    // or std::function
    auto my_lambda = [](){};
    return 0;
}
