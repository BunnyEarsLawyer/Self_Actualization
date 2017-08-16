//
// Static methods
// BAD CODE
//

#include<iostream>

class Node
{

public:

    Node();

    //
    // This static method should be private! 
    //

    // 
    // A static method can only access static data!
    // Remember that the static method 
    // does not have a this pointer passed into it 
    // 

    static int get_next_serial_number();

private:

    //
    // Static, 1 copy for the whole class
    //
    static int _next_serial_number;

    //
    // non-static, available to each object but not
    // to static methods
    //
    int _serial_number;

};

//
// Not inside the class delcaration --- we need to use Node
// as a prefix
//

// static int Node::_serial_number = 0; // @ non-compliant

int Node::_next_serial_number = 7;      // @ compliant

Node::Node()
   : _serial_number( get_next_serial_number() )
{

}

int Node::get_next_serial_number()
{
    // use the postfix version of ++
    // to return the value previously stored in the variable
    return _next_serial_number++;

}

int main()
{

    Node a;
    Node b;
    std::cout << a.get_next_serial_number << std::endl;
    std::cout << b.get_next_serial_number << std::endl;

}
