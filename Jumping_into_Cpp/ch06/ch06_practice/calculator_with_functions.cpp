// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Notice that if you divide by zero (e.g. 10/0) you get a floating point error
// There is also a file called 'core' created.
//


// Function Definitions
int add( int a, int b);
int subtract( int a, int b);
int multiply( int a, int b);
int divide( int a, int b);

// Program starts here 
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
              << " = " << multiply(first_argument, second_argument) 
              << std::endl;
    // Divide  
    std::cout << first_argument << " / " <<  second_argument 
              << " = " << divide(first_argument, second_argument) 
              << std::endl;
    // Add
    std::cout << first_argument << " + " <<  second_argument 
              << " = " << add(first_argument, second_argument) 
              << std::endl;
    // Subtract
    std::cout << first_argument << " - " <<  second_argument 
              << " = " << subtract(first_argument, second_argument) 
              << std::endl;
}

// Function implementation details 
int add( int a, int b)
{
    return a+b;
}

int subtract( int a, int b)
{
    return a-b;
}

int multiply( int a, int b)
{
    return a*b;
}

int divide( int a, int b)
{
    return a/b;
}
