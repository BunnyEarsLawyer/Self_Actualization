// Polymorphism and object destruction

#include<iostream>

//
// Superclass
//
class Drawable
{

public:

    //
    // Pure virtual function serves an interface
    //
    virtual void draw() = 0;

    //
    // B/c we don't want methods that use inherited objects
    // to have the ability to delete the object
    // Ensure the object is properly cleaned up
    // Defined inline
    //
    virtual ~Drawable() {}

};

//
// Subclass 
//
class MyDrawable : public Drawable
{

public:
    //
    // Inherited, MyDrawable defines its own version of draw
    //
    virtual void draw();

    MyDrawable();

    //
    // B/c we don't want methods that use inherited objects
    // to have the ability to delete the object
    // Ensure the object is properly cleaned up
    //
    virtual ~MyDrawable();

private:

    int *_my_data;

};

//
// Constructor and Destructor
//
MyDrawable::MyDrawable()
{

   // Dynamically allocates an int
    _my_data = new int;

    std::cout << "MyDrawable Constructor" << std::endl;

}

MyDrawable::~MyDrawable()
    {
    // Gives back memory allocated (from the free store/heap)
    delete _my_data;

    std::cout << "MyDrawable Destructor" << std::endl;

    }

void MyDrawable::draw()
{

    /*code that does drawing*/

}

void deleteDrawable ( Drawable *drawable)
{

    delete drawable;

    std::cout << "function deleteDrawable" << std::endl;

}

int main()
{

    deleteDrawable( new MyDrawable() );

}

