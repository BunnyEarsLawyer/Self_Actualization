
#include <string>
#include <iostream>

//
// For when you want to do a = b; You define what = means.
// Mostly b/c copying pointers is not good enough. 
// DOES NOT COMPILE! Insert function not defined
//

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
    // Assignment Operator:
    //
    LinkedList& operator=  (const LinkedList& rhs);

    //
    // Copy Constructor, similar to constructor 
    //
    LinkedList(const LinkedList& rhs);


    //
    // adds a node
    //
    void insert(int new_val); 

private:

    LinkedListNode *_p_head; 

};

// Constructor
LinkedList::LinkedList()
{
   
    

}

// Destructor 
LinkedList::~LinkedList()
{

    delete _p_head;

}

// Insert new node 
void LinkedListNode::insert(int new_val)
{

    new LinkedListNode;

    _p_head->val = new_val;

} 

LinkedList(const LinkedList& other);
    : _p_head(NULL) // in case the other list is empty
{

    LinkedListNode *p_itr = other._p_head;

    while( p_itr != NULL )
    {

        insert(p_itr->val);

    }

}


// Input: Const right hand side b/c we don't need to change the rhs
//        No need for a lhs, implied it's this class
// Output: Returns reference to a LinkedList
LinkedList& LinkedList::operator=  (const LinkedList& rhs)
{

    //
    // Make sure we aren't assigning to self
    // Use 'this' to ensure the rhs value isn't the
    // same address as our object
    //
    if ( this == & rhs)
    {
  
        //
        // Return this object to keep the chain of 
        // assignments alive
        //
        return *this;
    } 
    //
    // Free the old memory before copying over 
    // the new values
    delete _p_head;

    _p_head = NULL; 

    //
    // Repopulate the list with the new values
    //
    LinkedListNode *p_itr = rhs._p_head;

    while( p_itr != NULL )
    {

        insert(p_itr->val);

    }

    return *this;

}

int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    // LinkedList a;

} 

