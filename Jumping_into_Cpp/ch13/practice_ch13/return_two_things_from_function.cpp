//
// Structure example
// Asks for a persons name, phone number, and address 
//

#include <iostream>

//
// This function returns 2 things
// 1) a multiplication
// 2) an addition
// Since a function inherently returns one thing
// the second thing is record by reference 

//
// User should not enter a string for a number 
// User should not enter a number for a string 
// User should not enter values that overflow
// Address cannot have spaces 
// Cannot pick as many inputs as the user wants
//

int return_sum_and_multiplication(int input_a, 
                                  int input_b,
                                  int& multiplication_result)
{

     multiplication_result = input_a * input_b;

     return input_a + input_b;

}

int main()
{

    int a    = 2;
    int b    = 3;
    int mult = 0;
    int sum  = 0;

    sum = return_sum_and_multiplication( a, b, mult);

    std::cout << " a " << a; 

    std::cout << " b " << b; 

    std::cout << " sum " << sum; 

    std::cout << " multiplication " << mult << std::endl; 

}
