//
// IMPORTANT:
// How to build for debug and loading source: 
//   $g++ -g name_of_file.cpp -o blah_binary
// How to debug: 
//   $gdb ./blah_binary
//
// Using GDB Dashboard
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c
// (gdb) E.g. >>> print p_p_table
// (gdb) E.g. >>> print *p_p_table
//                print *(*p_p_table)            // 0
// (gdb) E.g. >>> print *(*p_p_table + 1)        // 1
// (gdb) E.g. >>> print *(*p_p_table + 1) + 1    // 2
// (gdb) b 72 
// (gdb) c // skips to break I set
// How to watch memory 
// (gdb) E.g. >>> dashboard memory watch 0x603010 4
// (gdb) p *p_p_table@3  // @ treats parts of memory as arrays. 
// $36 = {[0] = 0x603030, [1] = 0x603050, [2] = 0x0}
// >>> print *(p_p_table)
// $48 = (int *) 0x603030  
// >>> print *(p_p_table + 1)
// $49 = (int *) 0x603050

// (gdb) set $i = 0
// (gdb) print $i 
// (gdb) dashboard expression watch $i

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
//
//

int* grow_2d_array (int* p_values, int *size);

void print_multiplication_table(int * p_values,
                int size,
                int elements_set);

int main()
{

    //
    // Pointer to array holding n pointers
    //
    int n = 2;

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
    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            p_p_table[ii][jj] = ii;
 
        }

    }

    //
    // Printing out content
    //
    for (int ii = 0; ii < n; ++ii)
    {

        for (int jj = 0; jj < n; ++jj)
        {

            std::cout  << "ii " << ii << " jj "<<  jj << "\n "
                       << p_p_table[ii][jj] << std::endl;;

            std::cout  << "Pointer *p_p_table " << "\n "
                       << *p_p_table << std::endl;;
 
        }

    }


    //
    // Delete in reverse order
    //
    for (int ii = 0; ii < n; ++ii)
    {

        delete [] p_p_table [ii];
 
    }
    
    delete [] p_p_table;

    int x = 4; 

/*
*/

}

//
// Input:
// Pointer to first element in array (p_values)
// Pointer to size value             (size)
// Output: 
// Pointer to the first element of a new array (p_new_values)
//
int *grow_2d_array (int* p_values, int *size)
{
   //
   // Doubles the size of the array 
   // b/c it is inefficient to allocate memory 1-by-1
   //

   *size *= 2;

   int *p_new_values = new int [* size];
   
   for(int ii = 0; ii < *size; ++ii)
   {
       p_new_values [ii] = p_values [ii];
   }

   //
   // Careful to delete p_values after copying data
   // Else, we'd leak memory b/c we overwrite the pointer
   // that holds our array upon return from grow_2d_array
   //

   delete [] p_values;

   return p_new_values;

}

void print_multiplication_table(int * p_values,
                                int size,
                                int elements_set)
{

   std::cout << "The total size of the array is: " << size
             << std::endl;

   std::cout << "Number of slots set so far: " 
             << elements_set 
             << std::endl;

   std::cout << "Values in the array: " 
             << std::endl; 

   // Each element in the array points to another array

   for(int ii = 0; ii < elements_set; ++ii)
   {
           std::cout << "p_values[" << ii << ", " << ii << "]"
                     << p_values [ii]
                     << std::endl;

   } 

}
