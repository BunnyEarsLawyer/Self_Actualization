// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <algorithm>
#include <string>

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

    //auto words = {"ax,", "xa", "m", "\n"};
    vector<string> words = {"1 ", "2 ", "3 "};

    for ( vector<string>::iterator ii = words.begin(); ii != words.end(); ++ii )
    {

        for ( vector<string>::iterator jj = words.begin(); jj != words.end(); ++jj )
        {
            cout << *ii;
        }

    }

    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const string& word : words)
    {
        cout << word;
    }
    return 0;

}
