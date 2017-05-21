// How to build: $clang++ -std=c++11 <file_name>.cpp
// How to build: $gcc -std=c++11 <file_name>.cpp
// How to build: $g++ <file_name>.cpp -o hello
// How to build for debug: $g++ -g add_factored_primes.cpp -o blah
// How to debug: $gdb ./$MY_BINARY_NAME
// (gdb) break main
// (gdb) n
// (gdb) s
// (gdb) info locals 
// (gdb) list
// (gdb) c
#include <iostream>

//
// Program that turns finds all numbers from 1 to 1000 whose prime factors, 
// when added together, sum up to a prime number
// E.g. 12 has primes 2, 2, and 3 which sum to 7.  
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
// This only works for positive numbers
//
bool is_prime(int number)
{
    //
    // Exception b/c algorithm starts checking at 2
    //
    if(number == 2)
    {

        return true;

    }

    //
    // Starting after 2, if you find a number that can divide evenly, 
    // you are done. It's not a prime.
    //
    for(int ii = 2 ; ii < number; ++ii)
    {

        if(number % ii == 0)
        {

            return false;

        }

    }

    return true;

}

bool is_evenly_divisible(int number, int divisor)
{

    if(number % divisor == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int user_number    = 0; 
    int sum_of_primes  = 0; 

    user_number = ask_for_a_number();


    for(int ii = 2; ii < user_number; ++ii)
    {

        if(is_prime(ii))
        {

            if( is_evenly_divisible(user_number,ii) )
            {

                std::cout <<  "factor" << ii << std::endl;

                sum_of_primes += ii;

                user_number = user_number/ii;

                if(is_prime(user_number))
                {
                    std::cout <<  "factor" << user_number << std::endl;

                    sum_of_primes += user_number;

                }

                ii = 1;

            }
            
        }

    }    

    std::cout << "Sum of primes " <<  sum_of_primes << std::endl;
}



