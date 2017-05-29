Randomizing your code.

There are 2 ways to make code act differently
1. User inputs different inputs
2. Code behaves differently with the same input


You may not need truly random numbers. You can do well with 
pseudo-random numbers.

You supply a 'seed' and that seed gets fed back. For all intents
and purposes, the sequence looks random.

//
// C++ provides random numbers for you
//
void srand(int seed);

- Usully people put in the time as the seed

Side note: Unix time (32 bit integer) runs out on 2038. It started in January 1, 1970.
Interesting: Look up in WIKIPEDIA 'Year 2038 problem', computers will think it's 1901

//
// Include these two things
//
#include <cstdlib>
#include <ctime>

//
// For now just remember you feed NULL to the time function 
//
srand(time(NULL));

//
// Now you get random numbers with rand() 
//
int my_number = rand();

If you want a range of random numbers (e.g. 1-4) use modulus (%)

Modulus returns the remainder of a division (rounded to a whole number)

----------Testing and Debugging ------------
If you comment out srand() then rand() will return the same sequence.

If you find a bug after srand() is uncommented. Save the seed.


