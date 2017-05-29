// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

// Try entering 5.99 and notice it's truncated to 5
// Try entering a letter, like 'a', and notice it's 0 

int main()
{
    int x = 0;
    std::cout << "Output of x++ is " << x++ 
              << "\n b/c the compiler returns the value of x" 
              << "\n and then it uses ++ to add 1 to it " 
              << std::endl;

    std::cout << "Output of ++x is " << ++x 
              << "\n b/c the compiler first adds 1 to the value of x" 
              << std::endl;
}
