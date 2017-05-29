// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Prints out the squares of numbers 0 to 9
//
int main()
{
    for(int ii = 1; ii < 21; ++ii)
    {
        //
        // The loop checks the conditional statement before it loops again. 
        // When ii = 10, the loop breaks but ii is updated before the condition is checked.
        // The UPDATE step takes places after the loop started running.
        //
        std::cout << "ii is " << ii << " and squared it is " << ii*ii << std::endl;
    }
}
