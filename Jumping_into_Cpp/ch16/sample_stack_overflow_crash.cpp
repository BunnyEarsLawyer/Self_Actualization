// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

using namespace std;

// Ugh, I made it to this:57643017

void recurse(int count)
{
    cout << count << endl;
    // It is not necessary to increment count since each
    // function's varaibles are separate (so the count in each
    // stack frame will be initialized on greater than the last count)
    recurse(count+1);
}

int main()
{
    // First function call, so it starts at one
    recurse(1);
}
