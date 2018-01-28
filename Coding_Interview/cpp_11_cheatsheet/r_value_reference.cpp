// C++ 11: R-value reference 
// Used for 2 things:
//    1. Moving semantics
//    2. Perfect Forwarding

/*
Note 1: The most important place for rvalue reference is overloading
- copy constructor 
- copy assignment operator
E.g. 

X& X::operator=(X const & rhs);   // copy assignment operator
X& X::operator=(X && const rhs);  // overloaded copy assignment operator

Note 2: Move semantics is implemented for all STL containers in C++11.
This means your code will get faster w/out changin a thing.

Note 3: Pass by reference should only be used if you want to pass a variable back!

Not 4: Move constructor/ Move assignment operator
Purpose: avoid costly and unnecessary deep copying
1. Powerful where passing by reference and passing by value are used.
2. You have finer control

*/


//
// The most useful place for r-value reference
// is to overload 'copy constructor' and
// 'copy assignment operator' to achieve move semantics
//
#include<iostream>
using namespace std;

class boVector{

    int size;
    double* arr_; // a big array

public:
    //
    // Copy Constructor
    //
    boVector(const boVector& rhs)
    {
        size = rhs.size;
        arr_ = new double[size];

        // costly deep copy
        for(int i = 0; i < size; i++)
        {
	    arr_[i] = rhs.arr_[i];
        }
    }    

    //
    // Move Constructor
    //
    boVector(boVector&& rhs)
    {
        size = rhs.size;
        // no costly copy, instead
        // move the rhs's array to your new object
        // and just use it!
        arr_ = rhs.arr_;
        // however, you need to set that pointer to nullptr
        // rhs must not be const
        rhs.arr_ = nullptr;
    }
    // Destructor
    ~boVector() { delete arr_; }

};

// Invokes costly copy constructor
void foo(boVector v);
void foo_by_ref(boVector& v);
// Creates a BoVector
boVector createBoVector();

int main()
{

    boVector reusable = createBoVector();
    // 1st most efficient
    foo_by_ref(reusable); // No Constructor called

    // 3rd most efficient
    foo(reusable); // call Copy Constructor

    // 2nd most efficient
    // Moves reusable to the foo constructor
    // But be careful that reusable.arr_ = nullptr;
    // Really shouldn't use reusable after moving it.
    foo(std::move(reusable)); // call Move constructor

    //
    // createBoVector creates a temporary
    // object that is destroyed immediately
    //
    foo(createBoVector()); 

}
