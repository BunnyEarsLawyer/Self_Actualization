//
// IMPORTANT:
// How to build for debug and loading source: 
//   $g++ -g name_of_file.cpp -o blah_binary
// How to debug: 
//   $gdb ./blah_binary

/*
//
// p_p_table points to an array, its memory box contains an address
// The beginning of an array is also a pointer, its memory box contains address to an int
// Dereferencing twice will obtain the value of the int.
//
// Because the type is int, the sizeof(int) is 4 ... in my compiler

// REMEMBER: memory addresses is 48 bits long.
// Why do 64 bit systems have only 48 bit address space?
//://stackoverflow.com/questions/6716946/why-do-64-bit-systems-have-only-a-48-bit-address-space

// x86-64 (Also known as AMD64 and Intel 64) = 64 bit version of the x86 instruction set.

// For example, a single byte can have values ranging from 00000000 to 11111111 in binary form, 
// but this may be more conveniently represented as 00 to FF in hexadecimal.

// $92 Quatdrillion...
// The number 9,223,372,036,854,775,807, equivalent to the hexadecimal 
// value 7FFF,FFFF,FFFF,FFFF16, is the maximum value for a 64-bit signed integer in computing.

// Today an int is 4 bytes on 32 and 64 bit systems.
// Memory, here, is separated by steps of 8? Adding 1 to a pointer 
// will take you to the next memory box
// 
>>> p **p_p_table@2
$7 = {[0] = 0, [1] = 0}
>>> p **(p_p_table + 1)@2
$8 = {[0] = 1, [1] = 1}
>>> p p_p_table
$9 = (int **) 0x603010
>>> p p_p_table + 1
$10 = (int **) 0x603018
>>> p *(p_p_table + 1)
$11 = (int *) 0x603050
>>> p **(p_p_table + 1)
$12 = 1

*/


#include <iostream>

//
// This is for showing how to use pointer arithmetic
//


int main()
{

    //
    // Pointer to array holding n pointers
    //
    int n = 3;

    int array_size = n - 1;

    int ** p_p_table;

    p_p_table = new int*[ n ];

    //
    // Now make each pointer store the address of an array of integers
    //
    for (int ii = 0; ii < n; ++ii)
    {

        p_p_table[ii] = new int[n];
 
    }

    //
    // Now you can use the allocated memory like a 2D array
    //

    int counter = 0;

    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            p_p_table[ii][jj] = counter;

            ++counter;
 
        }

    }

    std::cout  << "sizeof(int)" << "\n "
               << sizeof(int) << std::endl;

    //
    // Printing out content
    //
    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            std::cout  << "(" << ii << "," <<  jj << ") = "
                       << p_p_table[ii][jj] << std::endl;

 
        }

    }

    std::cout  << "Pointer Dereferencing Twice **p_p_table " << "\n "
               << **p_p_table << std::endl;

    std::cout  << "Pointer Math *(*p_p_table + array_size*sizeof(int) + 1)" << "\n "
               << *(*p_p_table + array_size*sizeof(int) + 1) << std::endl;

    std::cout  << "Pointer Math *(*p_p_table + array_size*sizeof(int) + 2)" << "\n "
               << *(*p_p_table + array_size*sizeof(int) + 2) << std::endl;


    //
    // Delete in reverse order
    //
    for (int ii = 0; ii < n; ++ii)
    {

        delete [] p_p_table [ii];
 
    }
    
    delete [] p_p_table;

    int x = 4; 

}
