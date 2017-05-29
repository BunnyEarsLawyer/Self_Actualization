// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <string> 
#include <iostream> 

// Write a program that writes your name
int main()
{
    std::string user_name = "Ein";
    std::cout << "My name: " << user_name << std::endl;
}
