
#include <string>
#include <iostream>

//
// Node structure 
//

struct LinkedListNode
{

    int val;

    LinkedListNode *p_next;

};

//
// Class 
//

class LinkedList 
{

public:

    //
    // The constructor 
    //
    LinkedList();

    //
    // The destructor 
    //
    // We need to deallocate the head node pointer
    //
    ~LinkedList(); // <-- takes no arguments

    //
    // adds a node
    //
    void insert(int val); 

private:

    LinkedListNode *_p_head; 

};

/*
LinkedList()::LinkedList()
    : _p_head(NULL) // start with a NULL
{
}

LinkedList()::~LinkedList()
{
    delete _p_head;
}
*/

/*

// ------------------------------------------------
//
// B/c wouldn't it make more sense for each node to destruct its own data?
// What if we did this:
//
class LinkedListNode
{

public:

    ~LinkedListNode();

    int val;

    LinkedListNode *p_next;

}

LinkedListNode()::~LinkedListNode()
{
   //
   // Believe it or not this would start a chain of recursive function calls
   // The call to delete invokes the destructor for the object pointed to by p_next
   // Or does nothing if p_next is NULL
   // The destructor will, in turn, invoke the next destructor 
   // until NULL is reached
   // Finally, the other destructor, the one with _p_head, is invoked  
   //
    delete p_next;
}
*/
// ------------------------------------------------

int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    // LinkedList a;

} 

