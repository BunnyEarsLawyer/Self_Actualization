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
// Print out highest value
// lowest value
// average
// and all 50 values
//


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

//
// Declaring to use in sort function
//
int findLargest(int array[], int size);
int findSmallest(int array[], int size);
double findAverage(int array[], int size);

int main()
{

    int array_size = 50;

    int values [array_size];

    srand( time (NULL));

    for(int ii = 0; ii < array_size; ++ii)
    {
	
	values [ii] = rand() % 100;

    }
    
    cout << "Original array:\n";

    displayArray(values, array_size);

    cout << "\n";

    cout << "Smallest values " << findSmallest(values, array_size) << "\n";

    cout << "Largest values "  << findLargest(values, array_size)  << "\n";

    cout << "Average "         << findAverage(values, array_size)  << "\n";

}

double findAverage(int array[], int size) 
{
    
    double sum = 0;

    double average = 0;

    for(int ii = 0; ii < size; ++ii)
    {

	sum += array[ii];

    }
   
    average = sum/size;
 
    return average;

}

//
// Function to find largest element in the array 
//

int findLargest(int array[], int size)
{

    int index_of_largest_value = 0;

    for(int ii = 1; ii < size; ++ii)
    {

	if( array[ii] > array [index_of_largest_value] )
	{

	    index_of_largest_value = ii;

	}
	
    }
    
    return array[index_of_largest_value];

}

//
// Function to find smallest element in the array 
//

int findSmallest(int array[], int size)
{

    int index_of_smallest_value = 0;

    for(int ii = 1; ii < size; ++ii)
    {

	if( array[ii] < array [index_of_smallest_value] )
	{

	    index_of_smallest_value = ii;

	}
	
    }
    
    return array[index_of_smallest_value];

}
