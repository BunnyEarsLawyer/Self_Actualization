// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to build for debug: $g++ -g name_of_file.cpp -o blah
// How to debug: $gdb ./$MY_BINARY_NAME
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c
#include <iostream>

//
// Function that returns the sum of 
// all elements in a 1D array
//

//
// How would you write this without arrays? (with user input)
// - You would have no way of storing all the values
// - You'd have to immidiately add the sum when a user adds an input
// - You cannot show the numbers the user added.

int sumArray(int values[], int size)
{
    int sum = 0;

    //
    // Array stops when i == size b/c last element is size - 1
    //
    for(int ii = 0; ii < size; ++ii)
    {
	sum += values[ ii ];
	
    }

    return sum;
    
}

int main()
{
    //
    // Declares array that looks like a chessboard 
    //
    int values [10];

    for(int ii = 0; ii < 10; ++ii)
    {

	values [ii] = ii;	

    }
    
    std::cout << sumArray( values, 10) << std::endl;

}



