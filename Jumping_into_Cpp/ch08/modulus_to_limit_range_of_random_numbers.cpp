// How to build: $clang++ -std=c++11 name_of_program.cpp
// How to build: $gcc -std=c++11 name_of_program.cpp
// How to build: $g++ name_of_program.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <cstdlib>
#include <ctime>
//
// Modulus (%) returns the remainder e.g. 4/3 remainder is 1.
// If you divide a number by 4, remainder is b/c 0 and 3.
// If you divide your random number by the size of your range, you end up with a number 
// b/t 0 and the size of the range minus 1.
//
int randRange(int low, int high)
{
    //
    // We get a randome number, get it to be b/t 0 and the number of values in our range
    // E.g. 0 to 10 has 11 values.
    // E.g. 4 to 10 has 7 values.
    // then add the lowest possible value
    //
    return rand() % (high - low + 1) + low;
}

int main()
{
    //
    // Seed in the time
    // srand returns a random number b/t 0 and a constant called RAND_MAX = 32767 at least
    //
    srand( time(NULL) );
    for (int ii = 0; ii < 1000; ++ii)
    {
        std::cout << randRange(4,10) << " ";
    }
}
