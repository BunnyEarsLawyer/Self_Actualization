Inheritance and polymorphism:

Previously...

- Make clean public interfaces
- Support creating, copying, and cleaning up objects

Now...let's take the idea of interfaces further

E.g. You have a car, old and rusted. 

In this world, everyone makes a different steering mechanism (joysticks, mice, pedals, scroll bar)

Ugh..

Everytime you wanted to use a car (own or rent) you'd have to re-learn how to control it.

Fortunately there are standards, automatic or standard, and the details of the engine don't matter.

In C++, same thing.

- The interface is the same, the implementation details don't matter.

- When would you write code with similar property?

E.g. Video game
     
    Want to draw a bullet, ships, enemies.

    // Clear the Screen
    // Loop through list of drawable objects
    // For each, draw it

- We want a bunch of classes with the same interface but with different implementations of that interface.

E.g. what it means to be drawn

class Drawable
{

    public:

        void draw();

}

But the objects to be drawn are all different (e.g. bullet vs. ship) and have their own internal data.

For the loop that draws, all that stuff is irrelevant.

- Wouldn't it be great if we could create a 'vector<Drawable*>' and then store anything that implements
the draw method in that vector?  

* It's a pointer b/c you'll see...

If we can do the vector, then we just need to look over everything in the vector and call the draw method.

Anyone who wants to use objects in that vector only needs methos that make up the Drawable interface.

This exists!

---------------------------
Inheritance in C++

Vocab
- inheritance = one class gets traits from another class

- E.g. method we want to inherit is the 'draw' function

- subclass = a class that inherits from another class
           - A.K.A 'parent class' and 'child class'

- E.g. each Drawable object in a game will be a subclass of Drawable.
       each will inherit the property of having a 'draw' method
       each class will then implement their own version of 'draw', in fact, you have to

Syntax:

//
// The ": public Drawable" part indicates 
// the class Ship inherits from the class Drawable
//
class Ship : public Drawable
{

};

- Ship inherits ALL PUBLIC METHODS/DATA from class Drawable

Vocab 
- virtual = keyword that indicates you want to use the subclass's method
            and not the superclasses' method. You override what you inherited.

So you can do this:
Ship s;
s.draw(); // would involve the draw in the Drawable 

- Still not what we want

You must indicate that the 'draw' method can be overriden by subclasses. 
To do this use the keyword 'virtual'

class Drawable
{

public:

    virtual void draw();

};

- Sometimes you don't want the superclass to provide ANY implementation at all.
You want to force the subclass to have its own.

Vocab
- 'pure virtual' = you set a function to 0 to indicate it doesn't exist.
                   If a class has a pure virtual method, its subclasses must
                   implement the method.


class Drawable
{

public:
    //
    // Pure virtual
    //
    virtual void draw() = 0 ;

};

// The subclass must declare the method again, without the = 0

class Ship : public Drawable
{

public:
    virtual draw();

}

Ship::draw()
{

    /*code to do the drawing*/

}

Q: Why do we need a superclass Drawable at all if its draw method doesn't have any implementation?

A: To define the interface that all the subclasses will implement.
   Then we can write code that expects the Drawable interface without having to know the exact type of the class.

- some programming langs allow you to pass any object to any function
  as long as the object implements the methods used by that function.

C++, however, requires that a function be explicit about the interfaces 
of its arguments.


E.g. if we didn't have a Drawable interface, we couldn't even put these classes all in the same vector to begin with. There wouldn't be anything 'in common' to idenfity what to do in the vector.

----------------------------------------------------------------
E.g. this is the code for using our vector and drawing all the objects:

vector<Drawable*> drawables;

//
// store the Ship in the vector by creating a new Ship pointer
//
drawables.push_back( new Ship() );

for ( vector<int>::iterator itr = drawables.begin(),
                            end = drawables.end();
                            itr != end;
                            ++itr)
{

    //
    // Remember we need to use the -> syntax for calling
    // method when we have a pointer to an object
    //
    (*itr)->draw(); // calls Ship::draw

}

----------------------------------------------------------------

drawables.push_back( new Ship() );
drawables.push_back( new Enemy() );

:-) // We'll call the Ship::draw and the Enemy::draw

IMPORTANT: You need a 
vector<Drawable*>

NOT:
vector<Drawable>

Why? without the pointer, none of this will work!

B/c if we had 
vector<Drawable> drawables;

We now have memory with different Drawable objects

--------------------------------------------------------------------
[Drawable 1][Drawable 2][Drawable 3]
--------------------------------------------------------------------

BUT! each object may not be the same size.

// Is that still true? Do vectors store things sequentially like arrays?

--------------------------------------------------------------------
[pointer to Drawable 1][pointer to Drawable 2][pointer to Drawable 3]
--------------------------------------------------------------------

See Stack Overflow: Are all the data pointers of the same size in one
 platform?

vector<Drawable*>

Can put any kind of pointer we want into the vector as long as it is to a class that inherits from Drawable.

// Just b/c a vector fits doesn't mean it's a vector we want

REMEMBER: You need to pass the class around using a pointer whenever you want to have that class inherit an interface.

----------------------------------------
Summary of what we did:
1) Defined an interface (Drawable)
2) Any function can take a Drawable or any code that can work with a Drawable
   interface. 
   The code calls the 'draw' method that is implementted by the particular object it is pointed to.
3) Use the new types of the objects as long as they implement the drawable interface.
   The code that processes the objects doesn't need to know anything about them, it only needs to know they are Drawable.

Keyword
-reuse

Vocab
- Polymorphism = many forms

It's all about resuing code. When you create new objects, you make them inherit Drawable and now you can still use the vector Drawable objects.

You don't have to change existing code to be aware of new objects. This behavior is called 'polymorphism'

polymorphism:
- Every class that implements a particular interface is one form
- since code that is written to use just the interface can handle mutiple different classes...
- hence the code can support mutiple forms of the interface

E.g. Car with wheel and pedals
     Engine
        - Gas-powered
        - Hybrid
        - Pure Electric
-------------------------------------
USES & MISUSES OF INHERITANCE

- 'Polymorphism' depends on 'inheritance'

- 'Inheritance' can be used for more than just inherting an interface

    - You can use 'interitance' to pick up the implementation of a function

- Sometimes people believe that inheritance is about getting resuse from inheriting methods. However, this is a pretty limited form of reuse.

    -  How do you make sure that the implementation of that method is correct for every single subclass?

    E.g. You have 2 classes: Player and Ship
         Both inherit the virtual draw method from Drawable.
         What if you decide getName should not be virtual?

----------------------------------- 
class Drawable
{

public:

   string getName(); // not virtual, so daughter classes will inherit this 
                     // How do you make sure the implemntation is correct? :(
                     // What if you make a bullet class. It doesn't need a name!
                     // Every bullet does not need a name!

   virtual void draw() = 0;

}; 
----------------------------------- 
Inheritance, object construction and object destruction

----------------------------------------------------
#include <iostream>

using namespace std;

// Foo and Bar are a common placeholder names in computer programming

class Foo
{

public:
    Foo() { cout << "Foo's constructor" << endl; }
    ~Foo() { cout << "Foo's destructor" << endl; }

};

 
class Bar
{

public:
    Bar() { cout << "Bar's constructor" << endl; }
    ~Bar() { cout << "Bar's destructor" << endl; }

};

int main()
{
    Bar bar;
}
construction.cpp
----------------------------------------------------

Output:
//
// The superclass constructor runs first to initialize all fields
// This ensures that the subclass may use the fields in the superclass
// All done for you by the compiler
// Similarly, the destructor for the superclass will be called automatically
//

Foo's constructor 
Bar's constructor

Bar's destructor
Foo's constructor

- The constructor and destructor are called in opposite order 
  b/c we ensure Bar's destructor can safely use methods inherited from Foo
  b/c data those methods operate on is still in a valid usable state

 I don't get it.

- Sometimes you'll want to call a non-default destructor from the superclass.

-----------------------------------------
Polymorphism and object destruction:


 
