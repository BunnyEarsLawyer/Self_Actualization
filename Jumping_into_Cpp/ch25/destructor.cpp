
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

LinkedList::LinkedList()
    : _p_head(NULL) // start with a NULL
{
}

LinkedList::~LinkedList()
{
    
    LinkedListNode *p_itr = _p_head;

    while(p_itr != NULL)
    {

        LinkedListNode *p_tmp = p_itr->p_next;

        delete p_itr;

        p_itr = p_tmp;

    }

}

int main()
{

    //
    // The constructor is called on the very line where you create the object.
    //
    LinkedList a;

}  // Destructor is called at the end of the scope

