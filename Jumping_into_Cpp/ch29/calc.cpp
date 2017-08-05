// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
// typedef  my_type int
 
// Try entering 5.99 and notice it's core dump, floating point not expected 
// Try entering a letter, like 'a', and notice it's 0, floating point not expected 

class Calc
{
public:
    Calc ();

    int multiply (int x, int y);

    int add (int x, int y);

};

Calc::Calc ()
{}

int Calc::multiply (int x, int y)
{

    return x * y;

}

int Calc::add (int x, int y)
{

    return x + y;

}


int main()
{
    int first_argument;

    int second_argument;

    Calc c;

    std::cout << "Please enter first argument: " << std::endl;
    std::cin >> first_argument;
    std::cout << "Please enter second argument: " << std::endl;
    std::cin >> second_argument;

    // Add
    std::cout << first_argument << " + " <<  second_argument 
              << " = " << c.add(first_argument, second_argument); 

    std::cout << std::endl;

    // Multiply
    std::cout << first_argument << " * " <<  second_argument 
              << " = " << c.multiply(first_argument, second_argument); 

    std::cout << std::endl;

}
