//
// Structure example
// Asks for a persons name, phone number, and address 
//

#include <iostream>

//
// This function asks a user for their 
// first always asked 
// last only asked if user passes NULL 
// and two separate values

//
// User should not enter a string for a number 
// User should not enter a number for a string 
// User should not enter values that overflow
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

//
// Only asks for last name if no NULL pointer is passed
// Notice a pointer is used instead of a reference 
//
void prompt_user_1 (std::string& first_name,
                    std::string* last_name,
                    int& phone_number, 
                    int& id)
{

     std::cout << "Enter first name: "; 

     std::cin >> first_name;

     //
     // Notice we check the address here
     //
     if( last_name != NULL )
     {
         //
         // Notice we change the value pointed here
         // by derefencing the pointer with *
         //
         std::cout << "Enter last name: "; 

         std::cin >> *last_name;


     }
         
     std::cout << "Enter phone number: "; 

     std::cin >> phone_number;

     std::cout << "Enter id number: "; 

     std::cin >> id;

}

int main()
{

    PhonebookInfo citizen;

    //
    // Pass address if you want to change it
    // e.g. &citizen.last_name
    //
    citizen.last_name = "blah";

    //
    // Pass if you don't care to change last name
    //
    std::string* p_string = NULL;

    // If you need to be able to pass NULL,
    // then use pointers b/c a reference
    // assumes it referes to a valid object

    std::cout << "Warning: Do not enter letters when numbers expected\n";

    prompt_user_1 (citizen.first_name,
                   p_string,
                   citizen.phone_number, 
                   citizen.id);
   
    std::cout << citizen.first_name    <<"\n";

    std::cout << citizen.last_name     <<"\n";

    std::cout << citizen.phone_number  <<"\n";

    std::cout << citizen.id            <<"\n";

    std::cout << "Changing last name...\n";

    prompt_user_1 (citizen.first_name,
                   &citizen.last_name,
                   citizen.phone_number, 
                   citizen.id);

    std::cout << citizen.first_name    <<"\n";

    std::cout << citizen.last_name     <<"\n";

    std::cout << citizen.phone_number  <<"\n";

    std::cout << citizen.id            <<"\n";

}
