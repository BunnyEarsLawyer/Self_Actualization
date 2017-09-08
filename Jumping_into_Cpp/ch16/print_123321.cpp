// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

using namespace std;

void printNum(int num)
{

    //
    // The two calls in this function to cout will
    // sandwich an inner sequence containig the numbers 
    // (num+1)...99...(num+1)
    //
    cout << num;

    //
    // While begin is less than 9, we need to recursively print
    // the sequence for (num+1)...99...(num+1)
    //
    if( num < 9)
    {
       printNum( num + 1 );

    }

    cout << num;

}

int main()
{

    printNum(1);

    cout << endl;

}
