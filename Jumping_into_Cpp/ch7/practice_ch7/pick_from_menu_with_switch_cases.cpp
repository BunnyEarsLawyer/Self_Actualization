// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//

#include <iostream>

//
// Functions are called as needed 
//

void list_menu()
{
        std::cout << "This is the menu: " << std::endl;
        std::cout << "1. salmon   "       << std::endl;
        std::cout << "2. bread    "       << std::endl;
        std::cout << "3. steak    "       << std::endl;
}

int ask_customer_what_they_want()
{
        int temporary_choice_holder;

        std::cout << "Please enter the number of your pick: " << std::endl;

        std::cin >> temporary_choice_holder;

        return temporary_choice_holder;
}

bool get_customer_food(int user_pick)
{
    bool valid_choice = false;

    switch(user_pick)
    {

        case 1:
            std::cout << "salmon coming right up!\n";
            valid_choice = true;
            break;

        case 2:
            std::cout << "bread coming right up!\n";
            valid_choice = true;
            break;

        case 3:
            std::cout << "steak coming right up!\n";
            valid_choice = true;
            break;

        default:
            std::cout << "You picked: " << user_pick << std::endl;
            std::cout << "I am having trouble understanding :( Please try again " << std::endl;
            break;
    }

    return valid_choice;

}

//
// Program starts here 
//
int main()
{
    //
    // Variables used to store customer's choice and 
    // if they picked a valid choice from the menu
    //
    int customer_choice;
    bool did_user_pick_well = false;
    //
    // Will ask until you pick a choice from the menu 
    // or until the universe ends hehehe
    //
    while (!did_user_pick_well)
    {
        list_menu();
        customer_choice = ask_customer_what_they_want();
        did_user_pick_well = get_customer_food(customer_choice);
    }
}



