#include <iostream>
#include <vector>
#include <stack>
#include <list>

// See alias (c++11)
// Source: https://www.cs.cmu.edu/~cburch/survey/recurse/hanoiex.html

// Front lobe research: https://en.wikipedia.org/wiki/Tower_of_Hanoi

void print(std::stack<int> aa)
{
    // Make a copy of the input and pop one by one
    for(std::stack<int> dummy = aa; !dummy.empty(); dummy.pop() )
    {
        std::cout << dummy.top() << " ";
    }

    std::cout << "\n";
}
// call Tree
/*
A. source
B. destiny

3. move_pyramid(1,A,C,B) // MOVED 1 from A to C, return.
2. move_pyramid(2,A,C,B) //
1. move_pyramid(3,A,B,C)

Return
2. move_pyramid(2,A,C,B) // MOVE 2, from A to C, return 


*/



void move_pyramid(int disk_val, std::stack<int> & source, 
                                std::stack<int> & destiny, 
                                std::stack<int> & extra)
{

    if(disk_val == 1)
    {
        std::cout << "Value is smallest:" << disk_val << std::endl;

        if(!source.empty())
        {
            destiny.push(disk_val);
            source.pop();
        }

        std::cout << "Moved " << disk_val << std::endl;
    }
    else 
    {

        // Move from source to the extra
        move_pyramid(disk_val - 1, source, extra, destiny);

        // Move one from source to destiny
        if(!source.empty())
        {
            destiny.push(disk_val);
            source.pop();
        }

        std::cout << "Moved " << disk_val << std::endl;

        // Move from extra to the destiny 
        move_pyramid(disk_val - 1, extra, destiny, source);

    }

}


int main()
{
    // Goal: Move from tower A to tower B.

    std::stack <int> tower_A; 
    std::stack <int> tower_B;
    std::stack <int> tower_C;

    // Insert backwards so largest stack is at bottom
    for(int ii = 3; ii > 0; --ii )
    {
        tower_A.push(ii);
    }

    std::cout << "A ";
    print(tower_A);
    std::cout << "B ";
    print(tower_B);
    std::cout << "C ";
    print(tower_C);

    move_pyramid(3, tower_A, tower_B, tower_C);

    std::cout << "A ";
    print(tower_A);
    std::cout << "B ";
    print(tower_B);
    std::cout << "C ";
    print(tower_C);

}

