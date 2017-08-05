// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

// TODO: Should put template into a .hxx and the main part into a main.cpp
 
// Try entering 5.99 and notice it's not accepted b/c the inputs are put in ints. 
// Try entering a letter, like 'a', and notice it's 0, floating point not expected 

template <typename Type>
class Calc
{
public:
    Calc ();

    Type multiply (Type x, Type y);

    Type add (Type x, Type y);

};
/*
//old:
Calc::Calc ()
{}
*/

template <typename Type> Calc<Type>::Calc()
{}

/*
int Calc::multiply (int x, int y)
{
    return x * y;
}
*/

template < typename Type > Type Calc< Type >::multiply (Type x,
                                                        Type y)
{
    return x * y;
}

/*
int Calc::add (int x, int y)
{
    return x + y;
}
*/

template < typename Type > Type Calc< Type >::add (Type x,
                                                   Type y)
{
    return x + y;
}

int main()
{
    int first_argument;

    int second_argument;

    Calc<int> c;

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

}
