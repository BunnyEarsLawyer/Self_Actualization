// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
#include <typeinfo>
#include <vector>    // Use if not using auto

//source: http://en.cppreference.com/w/cpp/language/range-for

using namespace std;

int main()
{

    // vector of strings, vector<string> 
    auto words = {"axc,", "cax", "x"};

    //
    // Range based for loop
    //

    // Accessed by const reference
    for (const string& word : words)
    {
        cout << word;
    }
    
    // vector of ints 
    auto v = {0,1,2,3};

    //
    // Other ways to access:
    //
 
    // Access by value
    for (auto i : v)
        std::cout << i << ' ';

    std::cout << '\n';

    // Access by forwarding reference, type of i is int&
    for (auto&& i : v)
        std::cout << i << ' ';

    std::cout << '\n';

    // Access by f-d reference, type of i is const int& 
    const auto& cv = v;

    for (auto& i : v)
        std::cout << i << ' ';

    std::cout << '\n'; 

    //
    // Other construcs:
    //

    // The initializer may be braced-init-list 
    for (auto& n : {0,1,2})
        cout << n;

    std::cout << '\n';

    // The initializer may be an array 
    int a[] = {0,1,2};

    for (int n : a)
        cout << n;

    std::cout << '\n';

    // The loop array need not to be used
    for (int n : a)
        cout << 1;  // WOW... still iterates, just prints out 1's

    std::cout << '\n';

    // My way is for lists!?
    for(auto it = v.begin(); it != v.end(); ++it)
    {
       const auto& v = *it;
    }

    return 0;
}
