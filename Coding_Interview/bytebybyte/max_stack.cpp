// How to build: $clang++ -std=c++11 hello_world.cpp
// How to build: $g++ -std=c++11 hello_world.cpp      // YES
// How to build: $g++ hello_world.cpp -o hello        // NO!
// How to debug: $gdb ./$MY_BINARY_NAME
// gcc?
#include <iostream>
using namespace std;
//
// Design a stack with a push, pop, and max function
// All run in O(1) time
// Ask interviewer what kind of stack?
// - Last-in First out LIFO stack. 
// - Linked List, easy to do a LIFO stack
// E.g. push 1
//   3->2->1
// pop
// 2->1
// max = 3
// - Adding an additional field to Linked List, prev_max
//   2->3->2->1
//   V  V  V  V
// null 3  1  null 
//

struct LinkedListNode
{
     int value;
     LinkedListNode* p_next;
     LinkedListNode* p_old_max;
};

//
// Class 
//
class LinkedList
{
public:
    LinkedList();
    // We need to deallocate the head node pointer
    ~LinkedList(); 
    // adds a node
    void insert(int input);
    void pop();
    int get_max_value();
    void update_max(LinkedListNode* const & p_new);
    void print_list();
private:
    LinkedListNode *_p_head;
    LinkedListNode *_p_max;
};

LinkedList::LinkedList()
    : _p_head(nullptr), // start with a NULL
      _p_max(nullptr)   // start with a NULL
{
}

LinkedList::~LinkedList()
{
    LinkedListNode *p_itr = _p_head;

    while(p_itr != nullptr)
    {
        LinkedListNode *p_tmp = p_itr->p_next;
        delete p_itr;
        p_itr = p_tmp;
    }
}

void LinkedList::pop()
{
    if(_p_head != nullptr)
    {
        LinkedListNode* p_temp;
        p_temp = _p_head;
        _p_head = _p_head->p_next;
        delete p_temp;

    }
}

void LinkedList::print_list()
{
    LinkedListNode* p_current = _p_head;

    while(p_current != nullptr)
    {
        cout << p_current->value << " ";
        p_current = p_current->p_next;

    }
}

int LinkedList::get_max_value()
{
    return _p_max->value;
}

// Is the new value the largest value in the list?
void LinkedList::update_max(LinkedListNode* const & p_new )
{
    // If this is the first item, it's automatically the largest
    if(  _p_max == nullptr )
    {
       _p_max = p_new;
    }
    else
    {
        // Check against old max
        // if larger it becomes new max, point to the old max
        if( p_new->value > _p_max->value )
        {
            p_new->p_old_max = _p_max;
            _p_max = p_new;
        }
    }
}

void LinkedList::insert(int input)
{
    // This is how you allocate memory :)
    LinkedListNode* p_new_node = new LinkedListNode;

    p_new_node->value = input;

    update_max(p_new_node);

    p_new_node->p_next = _p_head;

    _p_head = p_new_node;

    p_new_node = nullptr;

}

int main()
{
    //
    // The constructor is called on the very line where you create the object.
    //
    LinkedList a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(2);

    a.print_list();

    cout << " max val " <<  a.get_max_value() << endl;

    a.pop();

    cout << " after pop ";

    a.print_list();

    // To execute please define "int main"
    auto words = {"Hellow,", "World!", "\n"};

    // O-notation
    // source: https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly
    //
    for (const string& word : words)
    {
        cout << word;
    }
    return 0;

}  // Destructor is called at the end of the scope
