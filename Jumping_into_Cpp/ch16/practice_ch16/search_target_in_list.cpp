// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>
#include <list>

//
// It's better to use std::list!
//

// Slow iterative search:
// Order in the stack of function calls:
// Step 3. search({3}, 3} = 3? yes, return answer. 
// Step 2. search({2,3}, 3} = 2? no search({3}, 3)
// Step 1. search({1,2,3}, 3} = 1? no search({2,3}, 3)
// search(list, target)

// Faster, binary search:
// Look at middle. Check if number is lower or higher or found.
// Not found? Go to lower or higher half. Repeat.

void print_list( std::list<int> vv)
{
    for( auto ii : vv)
    {
        std::cout << ii << " ";
    }
    std::cout << std::endl;
}

bool search(std::list <int> mylist, int target);

int main()
{
    std::list<int> mylist = {1,2,3,4,5,7,9,10};
    int target = 10;
    search(mylist, target);
    target = 1;
    search(mylist, target);

}

bool search(std::list <int> mylist, int target)
{
     if(mylist.empty())
     {
         return false;
     }

     print_list(mylist);

     int size = mylist.size();

     size_t halfway = size/2;

     std::list<int>::iterator it = mylist.begin();

     std::advance(it, halfway);

     int current_val = *it;

     if(current_val == target)
     {
         std::cout << "Target found: " << target << std::endl;
         return true;
     }
     else if( target > current_val )
     {
         // Search the top half of the list
         std::list <int> upper_list(it, mylist.end());
         print_list(upper_list);
         search(upper_list, target);

     }
     else if( target < current_val)
     {
         // Search the lower half of the list
         std::list <int> lower_list(mylist.begin(), it);
         print_list(lower_list);
         search(lower_list, target);
     }
     else
     {
         return false;
     }

}

