#include <iostream>
#include <vector>
#include <stack>
#include <list>

// See alias (c++11)
// Source: https://www.cs.cmu.edu/~cburch/survey/recurse/hanoiex.html
void print(std::stack<int> aa)
{
    // Make a copy of the input and pop one by one
    for(std::stack<int> dummy = aa; !dummy.empty(); dummy.pop() )
    {
        std::cout << dummy.top() << " ";
    }

    std::cout << "\n";
}
void move_pyramid(int disk_val, std::stack<int> & source, 
                                std::stack<int> & destiny, 
                                std::stack<int> & extra)
{

    if(disk_val == 1)
    {
        std::cout << "Value front :" << disk_val << std::endl;
        if(!source.empty())
        {
            destiny.push(disk_val);
            source.pop();
        }
    }
    else 
    {

        move_pyramid(disk_val - 1, source, extra, destiny);
        if(!source.empty())
        {
            destiny.push(disk_val);
            source.pop();
        }
        move_pyramid(disk_val - 1, extra, destiny, source);

    }
    std::cout << "src ";
    print(source);
    std::cout << "des ";
    print(destiny);
    std::cout << "ext ";
    print(extra);

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

