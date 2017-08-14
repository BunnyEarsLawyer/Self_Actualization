
#include <string>
#include <iostream>

//
// Node Class 
//

class LinkedListNode
{

public:

    ~LinkedListNode();

    int val;

    LinkedListNode *p_next;

};

//
// The advantage is that the destructor is called for you automatically.
//
LinkedListNode::~LinkedListNode()
{

//
// Starts chain of recursive function calls
// delete invokes the destructor for the object pointed to by p_next
// (or does nothing if p_next is NULL)
// until p_next is NULL
// The base case is hidden inside the call to delete.
//

    delete p_next;

}

//
// Linked List Class 
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

LinkedList::~LinkedList()
{

    delete _p_head;

}


int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    // LinkedList a;

} 

