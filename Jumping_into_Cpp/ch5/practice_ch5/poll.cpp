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
    int user_pick = 99;
    int number_of_polls_taken;
    int option_1 = 0;
    int option_2 = 0;
    int option_3 = 0;

    std::cout << "Welcome to the poll to see which is America's favorite pet!" << std::endl;

    //
    // Keep asking poll until user enter a correct option
    //
    while(user_pick != 0)
    { 

        std::cout << "These are the survey options: " << std::endl;

        std::cout << "1) Dog "                        << std::endl;

        std::cout << "2) Cat "                        << std::endl;

        std::cout << "3) Parakeet "                   << std::endl;

        std::cout << "Please enter the number of your pick: " << std::endl;

        std::cin >> user_pick;

    //
    // Why is this not working???? 
    //
//        switch(user_pick)
//        {
//
//            case 0:
//                break;
//
//            case 1:
//                option_1++;
//                break;
//
//            case 2:
//                option_2++;
//                break;
//
//            case 3:
//                option_3++;
//                break;
//
//            default:
//                std::cout << "Error, bad input." << std::endl;
//                continue;
//        }

        if(user_pick == 1)
            option_1++;

        if(user_pick == 2)
            option_2++;

        if(user_pick == 3)
            option_3++;

        std::cout << "You picked: " << user_pick << std::endl;

        number_of_polls_taken++;

        std::cout << "Please pass poll to the next user" << std::endl;

    }

    //
    // Keep asking poll until user enter a correct option
    //
    std::cout << "Poll results show:" << std::endl;
    std::cout << " " << option_1 << " is the number of people who like dogs \n" ;
    std::cout << " " << option_2 << " is the number of people who like cats \n" ;
    std::cout << " " << option_3 << " is the number of people who like parakeets \n" ;
}
