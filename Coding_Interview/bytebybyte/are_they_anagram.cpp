// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

// Given 2 strings, function to tell whether they are anagrams.
// Question: 26 English characters?
//           ASCII character
// Internationalization: Arabic, and other charcters sets.            
// Capitalization?
// "Banana" "banana", no worries.
// - Confirm with interviewer what to expect.
 
// Array: Count number of occurences in each character. 256 Array.
// Iterate, if values are the same, they are the same. If not they are different.
// Check if they have the same length.

bool is_anagram(string a, string b)
{
     sort(a.begin(), a.end());

     sort(b.begin(), b.end());

     if(a == b)
     {
          return true;
     }
     else
     {
          return false;
     }
}

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

    list<string> words = {"1a", "x2", "a1", "z3", "3z", "zz"};

    // Prints list 
    cout << "Result\n";
    for (const string& word : words)
    {
        cout << word << " ";
    }
 
    cout << endl;

    // Iterate through each item
    for ( list<string>::iterator ii = words.begin(); ii != words.end(); ++ii )
    {
        // E.g. ii = 1, jj = 1,2,3... then ii = 2, jj = 1,2,3...
        for ( list<string>::iterator jj = words.begin(); jj != words.end(); ++jj )
        {
            // Don't compare against yourself only to others
            cout << "where " << *ii << " " << *jj << endl; 
            if (&*ii != &*jj) 
            {
                  if( is_anagram(*ii, *jj) )
                  {
                     cout << "erase " << *ii << " " << *jj << endl; 
                     ii = words.erase(ii);
                     jj = words.erase(jj);

                     // Reset b/c the list has been removed!
                     if(!words.empty())
                     {
                         ii = words.begin();
                         jj = words.begin();
                     }
                  } 
            }
            else
            {
                cout << "same" << *ii << " " << *jj << endl; 
            }
        }
    }

    // Prints final result
    cout << "Result\n";
    for (const string& word : words)
    {
        cout << word;
    }
    cout << endl;

    return 0;

}
