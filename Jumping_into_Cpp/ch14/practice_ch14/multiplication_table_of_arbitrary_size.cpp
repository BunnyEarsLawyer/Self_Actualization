//
// IMPORTANT:
// How to build for debug and loading source: 
//   $g++ -g name_of_file.cpp -o blah_binary
// How to debug: 
//   $gdb ./blah_binary
//
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c

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
/*
  
    //
    // Now make each pointer store the address of an array of integers
    //
    for (int ii = 0; ii < 3; ++ii)
    {

        p_p_table[ii] = new int[n];
 
    }

    //
    //
    //
    for (int ii = 0; ii < 3; ++ii)
    {

        **p_p_table[ii] = ii;
 
    }

    //
    // Delete
    //
    for (int ii = 0; ii < 3; ++ii)
    {

        **p_p_table[ii] = ii;
        delete [] p_values;
 
    }


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