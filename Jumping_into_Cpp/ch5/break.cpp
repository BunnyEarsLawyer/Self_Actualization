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
    std::string password;
    while(1)
    {
        std::cout << "Enter your password please: ";
        std::cin >> password;
        if(password == "foobar")
        {
            break;
        }
    }
    std::cout << "Welcome! You got the password right \n";

}
