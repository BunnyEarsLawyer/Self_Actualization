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
#include <ctime>
#include <cstdlib>

using namespace std;

//
// Checks to see if an array is sorted. 
// If it isn't it sorts it using insertion sort. 
// Insertion sort, mostly unchanged sample from book.
// Works with any size!
//


//
// Declaring to use in sort function
//
int findSmallestRemainingElement (int array[], 
				  int size,
                                  int index);
void swap (int array[],
           int first_index,
           int second_index);

bool is_sorted(int array[], int size);
//
// INSERTION SORT: Finds smallest element and puts in in the front.
// Finds the second smallest element and puts it after the first one found,
// and so on 
//
void sort (int array[], int size)
{

    for(int ii = 0; ii < size; ++ii)
    {
	int index = findSmallestRemainingElement(array, 
                                                 size, 
                                                 ii);
        swap(array, ii, index);	
    }

}

void  displayArray(int array[], int size)
{
    cout << "{";
	
    for(int ii = 0; ii < size; ++ii)
    {
	if(ii != 0)
	{
		cout << ", ";
	}
	cout << array [ii];
    }
    
    cout << "}";
}

int main()
{
/* // for testing 
    int array_size = 3;
    int values [3] = {3,2,3};
*/
    int array_size = 0;
    cout << "Insert a size for the array: \n";
    cin >> array_size;

    int values [array_size];
    
    srand( time (NULL));
    for(int ii = 0; ii < array_size; ++ii)
    {
	
	values [ii] = rand() % 100;

    }
   
    cout << "Original array:\n";
    displayArray(values, array_size);
    cout << "\n";

    if(!is_sorted(values, array_size))
    {
        sort(values, array_size);

        cout << "Sorted array:\n";
        displayArray(values, array_size);
        cout << "\n";
    }


}


bool is_sorted(int array[], int size)
{
    // Loops until it finds a  
    // than the previous smallest value 
    for(int ii = 0; ii < size - 1; ++ii)
    {

	if( array[ii] > array [ii + 1] )
	{

	    cout << "array is not sorted\n";    

	    return false;

	}
	
    }

    cout << "array is sorted\n";    

    return true;
    
}
//
// Functions to swap and find smallest element
//
int findSmallestRemainingElement (int array[], 
				  int size,
                                  int index)
{

    int index_of_smallest_value = index;

    // Loops until it finds a value smaller 
    // than the previous smallest value 
    for(int ii = index + 1; ii < size; ++ii)
    {

	if( array[ii] < array [index_of_smallest_value] )
	{

	    index_of_smallest_value = ii;

	}
	
    }
    
    return index_of_smallest_value;

}


void swap (int array[],
           int first_index,
           int second_index)
{

    int temp = array[ first_index ];

    array[first_index] = array[second_index];

    array[second_index] = temp; 

} 
