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

    ~MyDrawable();

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

    std::cout << "Drawable Constructor" << std::endl;

}

MyDrawable::~MyDrawable()
{
    // Gives back memory allocated (from the free store/heap)
    delete _my_data;

    std::cout << "Drawable Destructor" << std::endl;

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


