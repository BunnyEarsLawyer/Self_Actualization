// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Functions are called as needed 
//

void play_game()
{
        std::cout << "1. Play game\n";
}

void load_game()
{
        std::cout << "2. Load game\n";
}

void play_multiplayer_game()
{
        std::cout << "3. Play multiplayer game\n";
}

void list_options()
{
        std::cout << "1. Play game\n";
        std::cout << "2. Load game\n";
        std::cout << "3. Play multiplayer game\n";
        std::cout << "4. Quit\n";
}

//
// Program starts here 
//
int main()
{
    int input = 0; 

    list_options();

    std::cout << "Enter selection\n";

    std::cin >> input;

    switch(input)
    {
        case 1:
            play_game();
            break;
        case 2:
            load_game();
            break;
        case 3:
            play_multiplayer_game();
            break;
        case 4:
            std::cout << "Thank you for playing!\n" << std::endl;
            break;

        default:
            std::cout << "Error: Bad input. Quitting\n" << std::endl;
            break;
    }

}
































