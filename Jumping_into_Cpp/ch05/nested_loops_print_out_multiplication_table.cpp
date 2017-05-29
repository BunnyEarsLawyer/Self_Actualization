// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Prints out a multiplication table nicely formatted
//
int main()
{
    for(int aa = 0; aa < 10; ++aa)
    {
        std::cout << "\t" << aa;
    }

    std::cout << "\n";

    for(int ii = 0; ii < 10; ++ii)
    {
        std::cout << ii;

        for(int jj = 0; jj < 10; ++jj)
        {
            std::cout << "\t" << ii*jj;
        }

        std::cout << "\n";

    }
}
