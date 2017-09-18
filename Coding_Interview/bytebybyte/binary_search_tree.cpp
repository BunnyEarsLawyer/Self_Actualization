// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
using namespace std;

//
// Valid Binary Search tree
//    5
//   /  \
//  2    7
// / \  / \
// 1 3 6  8
// - If there was a 5 child it has to be on the left.
// - Good place to start: is the left less than the parent, the right is more than the parent.
// - Everything on the left of the tree is < 5, on the right of the tree > 5 
// - Right side (has to be b/t 6 and infinity), Left (b/t 5 and neg. inf.)
// Keep track of the max and min

int main()
{
    // To execute please define "int main"
    auto words = {"Hellow,", "World!", "\n"};

    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const string& word : words)
    {
        cout << word;
    }
    return 0;
}
