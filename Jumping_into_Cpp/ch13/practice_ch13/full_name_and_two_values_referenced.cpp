//
// Structure example
// Asks for a persons name, phone number, and address 
//

#include <iostream>

//
// This function asks a user for their 
// first and last name
// and two separate values
// Function should return both values to the caller
// via additional pointer (or reference) parameters passed
// to the function.
//
// User should not enter a string for a number 
// User should not enter a number for a string 
// User should not enter vlues that overflow
// Address cannot have spaces 
// Cannot pick as many inputs as the user wants
//

struct PhonebookInfo
{

	std::string first_name;
	
	std::string last_name;

	int phone_number;

	int id;

};

void prompt_user_1 (std::string& first_name,
                    std::string& last_name,
                    int& phone_number, 
                    int& id)
{

     std::cout << "Enter first name: "; 

     std::cin >> first_name;

     std::cout << "Enter last name: "; 

     std::cin >> last_name;

     std::cout << "Enter phone number: "; 

     std::cin >> phone_number;

     std::cout << "Enter id number: "; 

     std::cin >> id;

}

void prompt_user_2 (PhonebookInfo & personal_info)
{

     std::cout << "Enter first name: "; 

     std::cin >> personal_info.first_name;

     std::cout << "Enter last name: "; 

     std::cin >> personal_info.last_name;

     std::cout << "Enter phone number: "; 

     std::cin >> personal_info.phone_number;

     std::cout << "Enter id number: "; 

     std::cin >> personal_info.id;

}


int main()
{
    //
    // Use references
    //

    PhonebookInfo citizen;

    prompt_user_1 (citizen.first_name,
                   citizen.last_name,
                   citizen.phone_number, 
                   citizen.id);
   
    std::cout << citizen.first_name    <<"\n";

    std::cout << citizen.last_name     <<"\n";

    std::cout << citizen.phone_number  <<"\n";

    std::cout << citizen.id            <<"\n";

}
