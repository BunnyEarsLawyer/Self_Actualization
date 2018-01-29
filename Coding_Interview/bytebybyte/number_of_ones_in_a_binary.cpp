// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?

//Read: https://www.swarthmore.edu/NatSci/echeeve1/Ref/BinaryMath/NumSys.html
// The number of bits to represent x is log(x)

#include <iostream>
using namespace std;

int main()
{

    int x;
    cout << "Enter a number: ";
    cin >> x;
    cout << "You entered :" << x << "\n";

    // 1 = 0b01
    // 2 = 0b10 // Shifted left by 1 (<< 1)
    // 3 = 0b01 // Shifted right by 1 (>> 1)

    cout << "------------\n";
    int y;
    y = x << 1;
    cout << "Shift input left by 1 and stored in y: \n" << y << "\n";
    y = y >> 1;
    cout << "Shift y right by 1 and stored in y: \n" << y << "\n";
    cout << "------------\n";

    // x = 0b00000001
    // x = 0b10000000
    cout << "You entered :" << x << "\n";

    int count_bits = 0;

    // While it's not 0, keep shifting right.
    // When the AND of the last bit is a 1, then add it to the counter. 
    while(x != 0){
        if(x & 1){
            count_bits++;
        }
        x = x >> 1;
    }

    cout << "There are " << count_bits << " ones in the number inputted\n";

}
