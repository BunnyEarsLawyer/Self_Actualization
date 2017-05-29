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
// Program that asks for 10 values and adds them.
// Image how you would do this without an array. 
// You'd have no easy way of storing the values entered.
// array_size did not exist in the original program
//
int sumArray (int values[], int size)
{
    int sum = 0;

    //
    // This loop stops when ii = size. Why?
    // Because the last element in the array is size - 1
    //
    for(int ii = 0; ii < size; ++ii)
    {
	
	sum += values[ii];
    }

    return sum;
}


int main()
{
    int array_size = 10;
    int values [array_size];

    for(int ii = 0; ii < array_size; ++ii)
    {

	std::cout << "Enter value: " << std::endl;

	std::cin >> values[ii];

    }
    
    std::cout <<  "Sum: " << sumArray(values, array_size) << "\n";

}



