//
// Static variables, only one is maintained 
// for all objects of the class
//

#include<iostream>

class Node
{

public:

    static int serial_number;

};

//
// Not inside the class delcaration --- we need to use Node
// as a prefix
//

// @non-compliant
//static int Node::serial_number = 0;

// @compliant
int Node::serial_number = 0;

int main()
{

Node a;
Node b;
std::cout << a.serial_number << std::endl;
std::cout << b.serial_number << std::endl;

}

