// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Turns numbers -999,999 to 999,999 to English text.  
//

int ask_for_a_number()
{
    int number;

    std::cout << "Please enter a number: " << std::endl;

    std::cin >> number;
    
    return number;
}

int get_hundreds_remainder( int number)
{
    int remainder = 0;

    remainder = number % 100; 

    return remainder;
}

//
// Functions that convert number to string
//
std::string get_ones_string(int number);
std::string get_tens_string(int number);

int main()
{
    std::string ones_place;
    std::string tens_place;
    std::string hundreds_place;
    std::string complete_string;

    int user_number = 0; 
    int remainder = 0;

    user_number = ask_for_a_number();

    if( user_number < 10 )
    {
        ones_place =  get_ones_string( user_number );
    }
    else if( user_number < 100 )
    {

        tens_place =  get_tens_string( user_number );

        if( user_number % 10 > 0)
        {
            
            remainder = user_number % 10;

            ones_place =  get_ones_string( remainder );

        }
    }
    
//    remainder = user_number % 10;
    
     

    complete_string = hundreds_place + " " + tens_place + " " + ones_place;

    std::cout << complete_string << std::endl;

}


std::string get_tens_string(int number)
{
    std::string number_in_text;

    int whole_number = number / 10;
        
    std::cout << whole_number << std::endl;

    switch(whole_number)
    {
        case 1:
            number_in_text = "ten";
            break;
        case 2:
            number_in_text = "twenty";
            break;
        case 3:
            number_in_text = "thirty";
            break;
        case 4:
            number_in_text = "forty";
            break;
        case 5:
            number_in_text = "fifty";
            break;
        case 6:
            number_in_text = "sixty";
            break;
        case 7:
            number_in_text = "seventy";
            break;
        case 8:
            number_in_text = "eighty";
            break;
        case 9:
            number_in_text = "ninety";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return number_in_text;
}

std::string get_ones_string(int number)
{
    std::string number_in_text;

    switch(number)
    {
        case 0:
            number_in_text = "zero";
            break;
        case 1:
            number_in_text = "one";
            break;
        case 2:
            number_in_text = "two";
            break;
        case 3:
            number_in_text = "three";
            break;
        case 4:
            number_in_text = "four";
            break;
        case 5:
            number_in_text = "five";
            break;
        case 6:
            number_in_text = "six";
            break;
        case 7:
            number_in_text = "seven";
            break;
        case 8:
            number_in_text = "eight";
            break;
        case 9:
            number_in_text = "nine";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return number_in_text;
}

