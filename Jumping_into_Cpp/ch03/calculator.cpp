// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
// typedef  my_type int
 
// Try entering 5.99 and notice it's core dump, floating point not expected 
// Try entering a letter, like 'a', and notice it's 0, floating point not expected 

int main()
{
    int first_argument;
    int second_argument;
    std::cout << "Please enter first argument: " << std::endl;
    std::cin >> first_argument;
    std::cout << "Please enter second argument: " << std::endl;
    std::cin >> second_argument;
    // Multiply
    std::cout << first_argument << " * " <<  second_argument 
              << " = " << first_argument * second_argument 
              << std::endl;
    // Divide  
    std::cout << first_argument << " / " <<  second_argument 
              << " = " << first_argument / second_argument 
              << std::endl;
    // Add
    std::cout << first_argument << " + " <<  second_argument 
              << " = " << first_argument + second_argument 
              << std::endl;
    // Subtract
    std::cout << first_argument << " - " <<  second_argument 
              << " = " << first_argument - second_argument 
              << std::endl;
}
