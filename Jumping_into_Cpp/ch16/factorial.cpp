// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $gcc -std=c++11 hello_world.cpp
// How to build: $g++ hello_world.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

using namespace std;

int factorial(int num)
{
    cout << num << endl;

    if( num == 1)
    {
       return 1;
    }
    else
    {
       return num * factorial( num - 1 );
    }
}

int main()
{
    cout << "result: " << factorial(3) << endl;
}
