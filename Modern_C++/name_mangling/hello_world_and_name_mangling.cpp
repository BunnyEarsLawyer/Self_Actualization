// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
// Run this: nm a.out | grep boom
// nm is a program that lists 'symbols' from object files
//
// History time! Originally Sroustrup created "C with classes"
// or cfront, a compiler that would translate early C++ to C.
// And the rest of the tools, C-compiler and linker, would be 
// used to produce object code. Which meant C++ names had to be
// translated to C somehow. That's 'name mangling'
//
// It provides a unique name for each class member and global/
// namespace function and variable.
//
// In C and C++ local (automatic) variables produce no symbols
// but live in registers or on the stack!
//
// 'Name mangling' is how the compiler keeps the linker happy.
// E.g. you can have 2 functions with the same name and different params
// the compiler mingles the name with the parameter types somehow.



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
    std::cout << "'Name mangling' is also known as 'decorating'" << std::endl;
}
