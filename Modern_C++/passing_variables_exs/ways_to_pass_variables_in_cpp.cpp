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

int main()
{
    std::string s1 = "pass by value";
    std::string s2 = "pass by reference";
    std::string s3 = "pass by const reference";
    std::string s4 = "pass by const reference";
    std::string s5 = "pass by const reference";
    std::string *p4 = &s4; 
    std::string *p5 = &s5; 

    std::cout << "s1: " << s1 << std::endl;

    pass_by_value( s1 );
    pass_by_reference( s2 );
    pass_by_const_reference( s3 ); 
    pass_const_pointer( p4 ); 
    pass_pointer( p5 ); 

}
