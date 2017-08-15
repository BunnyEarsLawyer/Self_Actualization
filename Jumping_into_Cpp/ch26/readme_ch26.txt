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






