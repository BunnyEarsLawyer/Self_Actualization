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
    vector<string> words = {"ax", "xa", "m"};
//    vector<string> words = {"1 ", "2 ", "3 "};

    vector<string> result;

    //
    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    // remove/erase idiom: https://stackoverflow.com/questions/347441/erasing-elements-from-a-vector

    // I'll just save the non-anagrams
    for ( vector<string>::iterator ii = words.begin(); ii != words.end(); ++ii )
    {
        for ( vector<string>::iterator jj = words.begin(); jj != words.end(); ++jj )
        {
            // Don't compare against yourself only to others
            // (This is not good life advice!)
            if (&*ii != &*jj) 
            {
//                cout << "ii " << *ii << endl;
//                cout << "jj " << *jj << endl;
                  cout << "where " << *ii << " " << *jj << endl; 
                  if( is_anagram(*ii, *jj) )
                  {
                     cout << "remove " << *ii << " " << *jj << endl; 
                     // Remove() does not really remove things.
                     // b/c 'remove()' DOES return the container's new 'end()'
 //                    words.erase(remove(words.begin(), words.end(), *ii));
//                     words.erase(
//                     remove(words.begin(), words.end(), *jj);
                     ii = words.erase(ii);
                  } 
            }
            else
            {
                cout << "same" << *ii << " " << *jj << endl; 
            }
        }
    }

    // Boost solution:
    // boost::remove_if(words, bind(&Player::is_anagram, _1)<=0 );

//    auto it = std::find(myVec.begin(), myVec.end(), obj37);
//    if (it != myVec.end()) { myVec.erase(it); }


    // Prints final result
    cout << "Result\n";
    for (const string& word : words)
    {
        cout << word;
    }

    return 0;

}
