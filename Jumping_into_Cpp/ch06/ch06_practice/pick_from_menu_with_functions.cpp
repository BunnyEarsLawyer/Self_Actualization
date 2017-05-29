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
        std::cout << "a) salmon   "       << std::endl;
        std::cout << "b) bread    "       << std::endl;
        std::cout << "c) steak    "       << std::endl;
}

std::string ask_customer_what_they_want()
{
        std::string temporary_choice_holder;
        std::cout << "Please enter the letter of your pick: " << std::endl;
        getline(std::cin, temporary_choice_holder, '\n');
        return temporary_choice_holder;
}

bool get_customer_food(std::string user_pick)
{
        if( user_pick == "a" | user_pick == "b" | user_pick == "c" )
        {
            std::cout << "You picked: " << user_pick << std::endl;
            std::cout << user_pick << " Coming right up!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "You picked: " << user_pick << std::endl;
            std::cout << "I am having trouble understanding :( Please try again " << std::endl;
            return false;
        }
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
    std::string customer_choice;
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
