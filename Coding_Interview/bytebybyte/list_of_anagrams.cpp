// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <typeinfo>
#include <vector>    // Use if not using auto

using namespace std;

int main()
{
    // Vector of strings, vector<string> words = {"axc,", "cax", "x"};
    auto words = {"axc,", "cax", "x"};

    // Range based for loop, accessed by const reference
    for (const string& word : words)
    {
        cout << word;
    }

    return 0;

}
