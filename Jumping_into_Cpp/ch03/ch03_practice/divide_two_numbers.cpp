// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream> 

// Write a program that writes your name
int main()
{

    double a;
    double b;
    std::cout << "Please enter first argument" << std::endl;
    std::cin >> a;
    std::cout << "Please enter second argument" << std::endl;
    std::cin >> b;
    // Divide 
    std::cout << "a / b = " << a / b << std::endl;
}
