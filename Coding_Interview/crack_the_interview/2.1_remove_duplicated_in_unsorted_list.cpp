// How to build: $clang++ -std=c++11 hello_world.cpp
#include <iostream>
// #include <algorithm>
#include <string>
#include <list> // Implemented as a doubly-linked list

using namespace std;

int main()
{

// Options: list::remove() - cannot resize
// Options: list::erase()  - deletes item in real time BUT pointers point to whatever is left 

// Options: a.erase(std::remove(a.begin(), a.end(), 1), a.end()); - remove what matches 1
//   remove/erase idiom: https://stackoverflow.com/questions/347441/erasing-elements-from-a-vector

// O-notation
// source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly

// Why did I not use a vector <string> ? B/c removing items from is a pain.
// std::list is better b/c we can remove things. It's a LinkedList!
// std::vector is basically an array!
//        auto words = {"ax,", "xa", "m", "\n"};
//        Also has options: vector::remove() and vector::erase()

/*
Because vectors use an array as their underlying storage, erasing elements in positions other than the vector end causes the container to relocate all the elements after the segment erased to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers
*/

// Other alternatives:

// auto it = std::find(myVec.begin(), myVec.end(), obj37);
// if (it != myVec.end()) { myVec.erase(it); }

// Boost solution:
// boost::remove_if(words, bind(&Player::is_anagram, _1)<=0 );

    list<int> numbers = {1,2,3,4,1};

    // Prints list 
    std::cout << "Result\n";
    for (int number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << endl;

    // Sort b/c in the words case, duplicate is at the very end of a large list
    // std::sort requires random access iterators, and 
    // std::list provides only bidirectional iterators.
    // std::list::sort(numbers)
    numbers.sort();
/*
    // Iterator 1: Iterate through each item
    for ( list<int>::iterator ii = numbers.begin(); ii != numbers.end(); ++ii )
    {

        // Iterator 2:  
        for ( list<int>::iterator jj = numbers.begin(); jj != numbers.end(); ++jj )
        {
            // Don't compare against yourself only to others
            std::cout << "where " << *ii << " " << *jj << endl; 
            if (&*ii != &*jj) 
            {
                  if( is_anagram(*ii, *jj) )
                  {
                     std::cout << "erase " << *ii << " " << *jj << endl; 
                     ii = numbers.erase(ii);
                     jj = numbers.erase(jj);

                     // Reset b/c the list has been removed!
                     if(!numbers.empty())
                     {
                         ii = numbers.begin();
                         jj = numbers.begin();
                     }
                  } 
            }
            else
            {
                std::cout << "same" << *ii << " " << *jj << endl; 
            }
        }
    }
*/
    // Prints final result
    std::cout << "Result\n";
    for (const int& number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << endl;

    return 0;

}
