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

    int number_of_polls_taken;

    int option_1 = 0;
    int option_2 = 0;
    int option_3 = 0;

    std::cout << "Welcome to the poll to see which is America's favorite pet!" << std::endl;

    //
    // Keep asking poll until user enter a correct option
    //
    while(number_of_polls_taken < 4)
    { 
        std::cout << "These are the survey options: " << std::endl;

        std::cout << "a) Dog "                        << std::endl;

        std::cout << "b) Cat "                        << std::endl;

        std::cout << "c) Parakeet "                   << std::endl;

        std::cout << "Please enter the letter of your pick: " << std::endl;

        getline(std::cin, user_pick, '\n');

        if( user_pick == "a" | user_pick == "b" | user_pick == "c" )
        {

            std::cout << "You picked: " << user_pick << std::endl;

            number_of_polls_taken++;

            if( user_pick == "a")
                option_1++;
            if( user_pick == "b")
                option_2++;
            if( user_pick == "c")
                option_3++;

            std::cout << "Please pass poll to the next user" << std::endl;

        }
        else
        {

            std::cout << "You picked: " << user_pick << std::endl;

            std::cout << "I am having trouble understanding :( Please try again " << std::endl;

        }
    }

    //
    // Keep asking poll until user enter a correct option
    //
    std::cout << "Poll results show:" << std::endl;
    std::cout << " " << option_1 << " is the number of people who like dogs \n" ;
    std::cout << " " << option_2 << " is the number of people who like cats \n" ;
    std::cout << " " << option_3 << " is the number of people who like parakeets \n" ;
}
