// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Functions are called as needed 
//

void sing_intro(int day)
{
        std::cout << "On the " << day 
                  << " day of Christmas my true love gave to me...\n";
}

//
// Program starts here 
//

int main()
{
    int input = 0; 

    std::cout << "Enter day of Christmas\n";

    std::cin >> input;

    sing_intro(input);

    switch(input)
    {
        case 12:
            std::cout << "12 true true love words\n";
        case 11:
            std::cout << "11 marshmallows\n";
        case 10:
            std::cout << "10 l'arc en ciel concerts\n";
        case 9:
            std::cout << "9 views from outter space\n";
        case 8:
            std::cout << "8 world peaces\n";
        case 7:
            std::cout << "7 harry potter books\n";
        case 6:
            std::cout << "6 mummy\n";
        case 5:
            std::cout << "5 tesserac\n";
        case 4:
            std::cout << "4 humanoid robot\n";
        case 3:
            std::cout << "3 xbox 360\n";
        case 2:
            std::cout << "2 motorcycle\n";
        case 1:
            if(input !=1)
            {
                std::cout << "and ";
            }
            std::cout << "a bird on top of a tree\n";
            break;

        default:
            std::cout << "Error: Bad input. Quitting\n";
            break;
    }

}
































