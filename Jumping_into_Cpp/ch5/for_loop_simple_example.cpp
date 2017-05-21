// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

int main()
{
    for(int ii = 0; ii < 10; ++ii)
    {
        std::cout << "ii is " << ii << std::endl;
    }
}
