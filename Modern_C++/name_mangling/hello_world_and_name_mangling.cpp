// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
// Run this: nm a.out | grep boom
// nm is a program that lists symbols from object files

#include <iostream>
#include <stdexcept>

namespace zoom
{

   void boom( const std::string& s)
   {
       throw std::runtime_error(s);
   }

}

int main()
{
    std::cout << "hello world" << std::endl;
}
