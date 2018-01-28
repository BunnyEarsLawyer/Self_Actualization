#include<iostream>


// A prime is a number only divisible by itself and 1
bool is_prime(int input)
{

    if(input == 2){ return true; }

    // Check all numbers up to input
    // If any number can evenly divide the input
    // Then the input number is not a prime
    for(int i = 2; i < input; i++)
    {
	if(input % i == 0)
        {
	    return false;
        }
    }

    return true;
}

void print_all_primes(int input_number)
{
    for(int i = 0; i < input_number; i++)
    {
	if(is_prime(i))
        {
	    std::cout << i << "\n";
	}		
    }
}


int main()
{
    std::cout << "is 1 prime: " << is_prime(1) << "\n";
    std::cout << "is 2 prime: " << is_prime(2) << "\n";
    std::cout << "is 3 prime: " << is_prime(3) << "\n";
    std::cout << "is 5 prime: " << is_prime(5) << "\n";
    std::cout << "is 6 prime: " << is_prime(6) << "\n";
    std::cout << "is 9 prime: " << is_prime(9) << "\n";
    std::cout << "is 23 prime: " << is_prime(23) << "\n";
    std::cout << "----------" << "\n"; 

    print_all_primes(100);

    return 0;
}
