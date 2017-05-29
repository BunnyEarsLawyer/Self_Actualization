// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>
//
// Will ask until infinity for your pick from the menu 
// Until you get it right
//
int main()
{
    std::string user_pick;

    while (1)
    {
        std::cout << "This is the menu: " << std::endl;

        std::cout << "a) salmon   "       << std::endl;

        std::cout << "b) bread    "       << std::endl;

        std::cout << "c) steak    "       << std::endl;

        std::cout << "Please enter the letter of your pick: " << std::endl;

        getline(std::cin, user_pick, '\n');

        if( user_pick == "a" | user_pick == "b" | user_pick == "c" )
        {

            std::cout << "You picked: " << user_pick << std::endl;

            break;

        }
        else
        {

            std::cout << "You picked: " << user_pick << std::endl;

            std::cout << "I am having trouble understanding :( Please try again " << std::endl;

        }
    }

    std::cout << user_pick << " Coming right up!" << std::endl;
    
}
