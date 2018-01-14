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

    list<int> numbers = {1,1,2,3,4,1};

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


    // Iterator 1: Iterate through each item
    for ( list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it )
    {

        // Oh no, C++ linked std::list does not have next(), I need a wrapper
        // uses #include <iterator> but I can use Boost too!
        // This means, I want the next one
        auto next = std::next(it, 1);

        if (*it == *next) 
        {
            std::cout << "same " << *it << " " << *next << endl; 

            // Options: list::remove() - cannot resize
            // Options: list::erase()  - deletes item in real time BUT 
            //          pointers point to whatever is left 

            // IMPORTANT: Notice it's not dereferenced, it deletes by position
            numbers.erase(next);

            // B/c the iterator will be incremented by 1 but there might be another duplicate 
            // A good question: Are there more than 1 duplicated values? E.g. 7 instances of a number
            it = std::prev(it,1);

        }

    }

    // Prints final result
    std::cout << "Result\n";
    for (const int& number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << endl;

    return 0;

}
