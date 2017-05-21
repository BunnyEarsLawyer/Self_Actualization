// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to debug: $gdb ./$MY_BINARY_NAME
//
#include <iostream>

//
// Program that turns numbers -999,999 to 999,999 to English text.  
//


//
// Function that asks for user input
//

int ask_for_a_number()
{
    int number;

    std::cout << "Please enter a number: " << std::endl;

    std::cin >> number;
    
    return number;
}

//
// Functions that convert number to string
//

std::string get_ones_string(int number);
std::string get_tens_string(int number);
std::string get_string_weirdos_between_10_and_20(int number);

int main()
{
    std::string negative_sign = "";
    std::string ones_place;
    std::string tens_place;
    std::string hundreds_place;
    std::string thousands_place;
    std::string tens_of_thousands_place;
    std::string hundreds_of_thousands_place;
    std::string complete_string;

    int user_number = 0; 
    int remainder = 0;

    user_number = ask_for_a_number();

    //
    // If the number is negative, add - in front of final answer
    //
    if(user_number < 0)
    {
        negative_sign = " negative ";
        user_number = user_number * (-1);
    }
    //
    // Hundreds of Thousands 
    //
    if( user_number % 1000000 > 0 && user_number >= 100000)
    {
       int hundreds_of_thousands_whole_number = user_number / 100000;
       
       hundreds_of_thousands_place =  get_ones_string( hundreds_of_thousands_whole_number );

       hundreds_of_thousands_place = hundreds_of_thousands_place + " hundred ";

       user_number = user_number % 100000;

    }
    //
    // Tens of Thousands 
    //
    if( user_number % 100000 > 0 && user_number >= 10000)
    {
        int tens_of_thousands_double_number = user_number / 1000;

        if( tens_of_thousands_double_number > 19) 
        {
            int tens_of_thousands_whole_number = user_number / 10000;

            tens_of_thousands_place =  get_tens_string( tens_of_thousands_whole_number );
       
            user_number = user_number % 10000;
        }
        else
        {
            tens_of_thousands_place = 
                get_string_weirdos_between_10_and_20(tens_of_thousands_double_number);
            
            user_number = user_number % 1000;

        }

    }
    //
    // Thousands 
    //
    if( user_number % 10000 > 0 && user_number >= 1000)
    {

       int thousands_whole_number = user_number / 1000;

       thousands_place =  get_ones_string( thousands_whole_number );
       
       thousands_place = thousands_place + " thousands "; 

       user_number = user_number % 1000;

    }
    //
    // Hundreds 
    //
    if( user_number % 1000 > 0 && user_number >= 100)
    {
        int hundreds_whole_number = user_number / 100;

        hundreds_place =  get_ones_string( hundreds_whole_number );

        hundreds_place = hundreds_place + " hundreds ";
        
        user_number = user_number % 100;

    }
    //
    // Tens 
    //
    if( user_number % 100 > 0 && user_number >= 10)
    {
        if( user_number > 19) 
        {
            int tens_whole_number = user_number / 10;
        
            tens_place =  get_tens_string( tens_whole_number );
        
            user_number = user_number % 10;
        }
        else
        {
            tens_place = get_string_weirdos_between_10_and_20(user_number); 
            
            user_number = 0;
        }
    }
    //
    // Ones 
    //
    if( user_number % 10 > 0)
    {
            
        remainder = user_number % 10;

        ones_place =  get_ones_string( remainder );

    }
   
    if( tens_of_thousands_place == "zero" )
        std::cout << "zero" << std::endl;

    complete_string = negative_sign
                    + hundreds_of_thousands_place  
                    + tens_of_thousands_place 
                    + thousands_place
                    + hundreds_place 
                    + tens_place 
                    + ones_place;

    std::cout << complete_string << std::endl;

}



std::string get_string_weirdos_between_10_and_20(int number)
{
    std::string number_in_text;

    switch(number)
    {
        case 11:
            number_in_text = " eleven ";
            break;
        case 12:
            number_in_text = " twelve ";
            break;
        case 13:
            number_in_text = " thirteen ";
            break;
        case 14:
            number_in_text = " forteen ";
            break;
        case 15:
            number_in_text = " fifteen ";
            break;
        case 16:
            number_in_text = " sixteen ";
            break;
        case 17:
            number_in_text = " seventeen ";
            break;
        case 18:
            number_in_text = " eighteen ";
            break;
        case 19:
            number_in_text = " nineteen ";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return number_in_text;
}

std::string get_tens_string(int number)
{
    std::string number_in_text;

    switch(number)
    {
        case 1:
            number_in_text = " ten ";
            break;
        case 2:
            number_in_text = " twenty ";
            break;
        case 3:
            number_in_text = " thirty ";
            break;
        case 4:
            number_in_text = " forty ";
            break;
        case 5:
            number_in_text = " fifty ";
            break;
        case 6:
            number_in_text = " sixty ";
            break;
        case 7:
            number_in_text = " seventy ";
            break;
        case 8:
            number_in_text = " eighty ";
            break;
        case 9:
            number_in_text = " ninety ";
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
        case 1:
            number_in_text = " one ";
            break;
        case 2:
            number_in_text = " two ";
            break;
        case 3:
            number_in_text = " three ";
            break;
        case 4:
            number_in_text = " four ";
            break;
        case 5:
            number_in_text = " five ";
            break;
        case 6:
            number_in_text = " six ";
            break;
        case 7:
            number_in_text = " seven ";
            break;
        case 8:
            number_in_text = " eight ";
            break;
        case 9:
            number_in_text = " nine ";
            break;

        default:
            std::cout << "Error: I don't know how to write this input \n" << std::endl;
            break;
    }

    return number_in_text;
}

