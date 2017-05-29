// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

int main()
{

    int ii = 0;        // Variable declaration and initialization
    while (ii < 10)    // Condition
    {
        std::cout << ii << '\n';
        ii++;          // Variable update    
    }

}
