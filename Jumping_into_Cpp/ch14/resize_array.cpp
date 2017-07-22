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
// This program will keep asking for a number
// and storing them in a growing array until
// the user decides to enter 0
//

int *growArray (int* p_values, int *size);

void printArray(int * p_values,
                int size,
                int elements_set);

int main()
{
    int next_element = 0;
    int size = 10;
    int *p_values = new int[ size ];
    int val;
    std::cout << "Please enter a number: ";
    std::cin >> val;
    while (val > 0)
    { 
        if (size == next_element + 1 )
        {
            //
            // Notice we need to pass in size as a pointer
            // b/c we need to keep track of the array as it grows
            //
            p_values = growArray(p_values, & size);
        }
    p_values[next_element] = val;
    next_element++;
    std::cout << " Current array values are: " << std::endl;
    printArray( p_values, size, next_element );
    std::cout <<  "Please enter a number (or 0 to exit):";
    std::cin >> val;
    }
}

int *growArray (int* p_values, int *size)
{

   *size *= 2;

   int *p_new_values = new int [* size];
   
   for(int ii = 0; ii < *size; ++ii)
   {
       p_new_values [ii] = p_values [ii];
   }

   delete [] p_values;

   return p_new_values;

}

void printArray(int * p_values,
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

   for(int ii = 0; ii < elements_set; ++ii)
   {

       std::cout << "p_values[" << ii << "] = "
                 << p_values [ii] 
                 << std::endl;

   } 

}
