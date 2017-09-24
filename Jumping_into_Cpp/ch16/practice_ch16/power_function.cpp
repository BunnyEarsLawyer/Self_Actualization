// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

using namespace std;

// Power (x,y) = x^y
// Step 4. power(1,1) = 1
// Step 3. power(2,1) = 2*power(1,1)
// Step 2. power(2,2) = 2*power(2,1)
// Step 1. power(2,3) = 2*power(2,2)
// power(x,y) = x*x*x*x...*x
// power(2,3) = 2*2*2 

int power(int base, int exponent)
{
    cout << "base" << base  << "exp"  << exponent << endl;

    if( base <= 0 | exponent <= 0 )
    {
       return 0; //error, invalid inputs
    }
    else if( base >= 0 && exponent == 1)
    {
       return base;
    }
    else
    {
       return base * power(base , exponent - 1 );
    }
}

int main()
{
    cout << "result: power(2,3) = " << power(2,3) << endl;
}
