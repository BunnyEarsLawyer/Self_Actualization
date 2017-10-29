// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
// Run this: nm a.out | grep boom
// nm is a program that lists 'symbols' from object files
//

// Self-documenting code with precision

#include <iostream>
#include <stdexcept>

namespace zoom
{
   // Takes ownership
   void pass_by_value( std::string s)
   {
   }
   // Required, modifies
   void pass_by_reference( std::string& s)
   {
   }
   // Required, read-only 
   void pass_by_const_reference( const std::string& s)
   {
   }
   // Optional, read-only 
   void pass_const_pointer( std::string const *s)
   {
   }
   // Optional, modifies 
   void pass_pointer( std::string *s)
   {
   }

}

int main()
{
    std::cout << "hello world" << std::endl;
    std::string s1 = "inti";
}
