//
// Structure example
// Asks for a persons name, phone number, and address 
//

#include <iostream>

//
// This function compares the memory addresses of two different variables 
// on the stack. 
// Prints out the numerical order of the addresses. 
//

//
// pg. 170 table is very useful!
//

//
// Assumptions:
// User should not enter a string for a number 
// User should not enter a number for a string 
// User should not enter values that overflow
//

//
// Goal: Explore x86 calling conventions
//       how parameters are passed (pushed on the stack)
//       placed in registers or a mix of both.
//       https://en.wikipedia.org/wiki/X86_calling_conventions
// Input: two pointers
// Output: none, prints out order of address
//
void compare_memory_and_print_by_order(int* p_1, 
                                       int* p_2)
{

    std::cout << " The first value passed is " << *p_1 << std::endl;
    std::cout << " The second value passed is " << *p_2 << std::endl;

    if( p_1 > p_2)
    {

        std::cout << " higher address " << p_1
                  << " from value "     << *p_1
                  << std::endl; 

        std::cout << " lower address " << p_2
                  << " from value "    << *p_2 
                  << std::endl; 

    }
    else
    {

        std::cout << " higher address " << p_2 
                  << " from value "    << *p_2 
                  << std::endl; 

        std::cout << " lower address " << p_1
                  << " from value "     << *p_1
                  << std::endl; 

    } 

}

int main()
{

    int a    = 1;
    int b    = 2;

    //
    // Pointers that will hold the 
    // addresses of the variables
    //

    int *p_a;
    int *p_b;
    
    p_a = &a;
    p_b = &b;

    compare_memory_and_print_by_order(p_a, p_b);

}
