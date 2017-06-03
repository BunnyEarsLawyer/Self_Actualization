//
// Structure example
// Asks for a persons name, phone number, and address 
//

#include <iostream>

//
// User should not enter a string for a number 
// User should not enter a number for a string 
// User should not enter vlues that overflow
// Address cannot have spaces 
// Cannot pick as many inputs as the user wants
//
struct PhonebookInfo
{

	std::string name;

	int phone_number;
	
	std::string address;

};

int main()
{
	//
	// Like normal variable types, 
        // You can make arrays of structures
	//

	PhonebookInfo citizens[5];

	for(int ii = 0; ii < 5; ++ii)
	{
		std::cout << "Enter name for citizen in phonebook: " << ii << "\n";
		
		std::cin >> citizens[ii].name;

		std::cout << "Enter phone number for citizen: " << ii << "\n";

		std::cin >> citizens[ii].phone_number;

		std::cout << "Enter address for citizen: " << ii << "\n";

		std::cin >> citizens[ii].address;
	}


	for(int ii = 0; ii < 5; ++ii)
	{
		std::cout << "Citizen "             << citizens[ii].name 
		          << " has a phone number " << citizens[ii].phone_number
		          << " has address "        << citizens[ii].address
                          << "\n";
		

	}

}
