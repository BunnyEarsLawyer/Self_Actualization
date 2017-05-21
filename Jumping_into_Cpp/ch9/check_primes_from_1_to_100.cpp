// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Print primes that are in between 0 and 100
// Prime = a number that can be divided by 1 and itself only
//

bool isDivisible ( int number, int divisor);
bool isPrime (int number);

int main()
{
    // 
    // This will only print numbers that are primes
    //

    for(int ii = 0; ii < 100; ++ii)
    {
        if ( isPrime( ii ) )
        {
            std::cout << ii << std::endl;
        }
    }
}

bool isPrime (int number)
{
    //
    // Canno divide by 0, skip 1 b/c it's redundant
    //

    for ( int jj = 2; jj < number; ++jj)
    {
        if ( isDivisible( number , jj) )
        {
            return false;
        }
    }

    return true;
}

bool isDivisible(int number, int divisor)
{
    //
    // Modulus % returns the remainder of a division.
    // e.g. 10/5 = 2 with 0 remainder
    // If it's == 0, returns true. False otherwise.
    //
    
    return number % divisor == 0;
}




