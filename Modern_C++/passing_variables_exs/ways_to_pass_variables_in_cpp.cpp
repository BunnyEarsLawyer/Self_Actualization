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
    s = "modification";
    std::cout << "#1 s: " << s
              << ", can modify input but original not affected" << std::endl;
}
// Required, modifies
void pass_by_reference( std::string& s)
{
    s = "modification";
    std::cout << "#2 s: " << s
              << ", can modify input, original input also changed" << std::endl;
}
// Required, read-only 
void pass_by_const_reference( const std::string& s)
{
// CANNOT MODIFY ^_^ 
/* E.g.
In function ‘void pass_by_const_reference(const string&)’:
ways_to_pass_variables_in_cpp.cpp:30:7: error: passing ‘const string {aka const std::basic_string<char>}’ as ‘this’ argument of ‘std::basic_string<_CharT, _Traits, _Alloc>& std::basic_string<_CharT, _Traits, _Alloc>::operator=(const _CharT*) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]’ discards qualifiers [-fpermissive]a 
*/
//  s = "modification";
    std::cout << "#3 s: " << s 
              << ", cannot modify input" << std::endl;
}
// Optional, read-only 
void pass_const_pointer( std::string const *p)
{
    std::string z = "modification";
    p = &z;
    std::cout << "#4 p: " << p << " " << *p 
              << ", can modify input" << std::endl;
}
// Optional, modifies 
void pass_pointer( std::string *p)
{
    std::string z = "modification";

    *p = z;
    std::cout << "#5 p: " << p << " " << *p 
              << ", can modify input, original string also changed " << std::endl;

}

int main()
{
    std::string s1 = "pass by value";
    std::string s2 = "pass by reference";
    std::string s3 = "pass by const reference";
    std::string s4 = "pass const pointer";
    std::string s5 = "pass pointer";
    std::string *p4 = &s4; 
    std::string *p5 = &s5; 

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "*p4: " << p4 << " " << *p4 << std::endl;
    std::cout << "*p5: " << p5 << " " << *p5 << std::endl;

    // Takes ownership
    pass_by_value( s1 );
    // Required, modifies
    pass_by_reference( s2 );
    // Required, read-only 
    pass_by_const_reference( s3 ); 
    // Optional, read-only 
    pass_const_pointer( p4 ); 
    // Optional, modifies 
    pass_pointer( p5 ); 

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "*p4: " << p4 << " " << *p4 << std::endl;
    std::cout << "*p5: " << p5 << " " << *p5 << std::endl;

}
