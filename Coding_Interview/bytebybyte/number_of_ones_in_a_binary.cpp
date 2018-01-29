// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?

//Read: https://www.swarthmore.edu/NatSci/echeeve1/Ref/BinaryMath/NumSys.html
// The number of bits to represent x is log(x)

#include <iostream>
using namespace std;

int ones_in_binary( int x )
{

    return 0;    
   
}

int main()
{

    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered :" << x << "\n";

    // 1 = 0b01
    // 2 = 0b10 // Shifted left by 1 (<< 1)
    // 3 = 0b01 // Shifted right by 1 (>> 1)

    int y;
    y = x << 1;
    cout << "Shift x left by 1 and stored in y: \n" << y << "\n";
    y = y >> 1;
    cout << "Shift y right by 1 and stored in y: \n" << y << "\n";


/*
    // To execute please define "int main"
    auto words = {"Hellow,", "World!", "\n"};

    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const string& word : words)
    {
        cout << word;
    }
*/
}
