// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// It's better to use std::list!
//

using namespace std;

// Order in the stack of function calls:
// Step 4. array_in_reverse([\n]) = print \n 
// Step 3. array_in_reverse([3, \n]) = print 3  
// Step 2. array_in_reverse([2,3, \n]) = print 2 
// Step 1. array_in_reverse([1,2,3, \n]) = print 1 

// array_in_reverse(array [1,2,3]) = 3,2,1
// array...


// Pass array into a function, it's actually a pointer.
void array_in_reverse(int in_array[], int size)
{

    if(size > 0 )
    {
        cout << in_array[0] << endl;

        // Pointer arithmetic.
        int *smaller_array = in_array + 1;

        array_in_reverse(smaller_array, size - 1);

    }
    else
    {
        cout << " no more items! ";
    }
}

int main()
{
    int size = 3;
    int my_array[] = {1,2,3};
    array_in_reverse(my_array, size);

}
