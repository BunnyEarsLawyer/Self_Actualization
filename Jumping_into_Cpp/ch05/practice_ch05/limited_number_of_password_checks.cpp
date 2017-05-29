// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Checks password for a limited number of times.
// No password checker is that simple.
// For starters, it wouldn't be included in the source code.
//
int main()
{
    std::string password;

    for(int ii = 0; ii < 3; ++ii)
    {
	    
	    std::cout << "Please enter your password: " << std::endl;
	
	    getline(std::cin, password, '\n');
	
	    if(password == "password")
	    {

            std::cout << "Access Allowed" << std::endl;

            break;

        }
	    else
	    {

            std::cout << "Access Denied!" << std::endl;

        }

    }    

}
