// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <bitset>
using namespace std;

// Given 2 integers, determine if they differ by exactly 1 bit.

//e.g.
// gray(0,1) = true
// gray(1,2) = false 


// My notes:
// nor  = ~(a | b)
// nand = ~(a & b)
// nor = (~a) & (~b)
// nand = (~a) | (~b)

// Bit shift by n bits, takes 2 argumenst:
// x << n
// x >> n

int count_bit_ones(int z)
{

    int counter = 0;
    cout << "1. count how many ones"  << bitset<8> (z) << endl;

    // Shift bits to the right by 1 until it's zero.
    // Count how many times you shifted
    while(z != 0)
    {

        z >>= 1;
        cout << "2. count how many ones"  << bitset<8> (z) << endl;

        ++counter;
        
    }

    return counter;
}

bool gray(int a, int b)
{

    cout << "a"  << bitset<8> (a) << endl;
    cout << "b"  << bitset<8> (b) << endl;

    int result = a ^ b;

    cout << "result" << bitset<8> (result) << endl;

    if(count_bit_ones(result) == 1)
    {
        cout << "Differs by at 1 bit" << endl;
        return true; 
    }
    else
    {
        return false; 
    }

}

int main()
{

    int x = 0;
    int y = 3;

    gray(x,y);

    return 0;
}
