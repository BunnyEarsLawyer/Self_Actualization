// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>
//
// Will ask until infinity for your password
// Until you get it right. But it uses 'break'
//
int main()
{
    int ii = 0;

    while(true)
    {
        ii++;

        if(ii == 10)
        {
            continue;               //Skips printing 10
        }

        std::cout << ii << "\n";

        if(ii == 15)
        {
            break;              
        }


    }

}
