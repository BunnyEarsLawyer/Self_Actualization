// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

using namespace std;

int factorial_even(int x);
int factorial_odd(int x);
// Ugh, I made it to this:57643017

int factorial_odd(int x)
{
    cout << "odd" << x << endl;
    if(x==0)
    {
        return 1;
    }
    return factorial_even(x-1);
}

int factorial_even(int x)
{
    cout << "even" << x << endl;
    if(x==0)
    {
        return 1;
    }
    return factorial_odd(x-1);
}

int factorial(int x)
{
    cout << "factorial" << x << endl;

    if(x % 2 == 0)
    {
        return factorial_even(x);
    }
    else
    {
        return factorial_odd(x);
    }
}


int main()
{
    factorial(5);
    // Make sure to put cout statements! Otherwise your computer will freeze.
    factorial(-1);
}
