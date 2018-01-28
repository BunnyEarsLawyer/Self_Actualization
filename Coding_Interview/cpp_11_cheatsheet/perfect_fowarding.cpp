// C++ 11: R-value reference 
// Used for 2 things:
//    1. Moving semantics
//    2. Perfect Forwarding <--

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

Note 5: Universal Reference has &&
void relay(int&& input){....}

// Templatized relay function uses 
// universal reference ('T ref ref' = T&&)  
template< typename T>
void relay(T&& arg)
{
    foo( std::forward<T>(arg));
}

*/

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

// boVector has both move constructor and copy constructor
void foo( boVector arg);
// Creates boVector
boVector createBoVector();

// Argument fowarding: template function 
// passes argument to function foo() 

/*
SOLUTION Requirements:
a. same type, rvalue forward as rvalue, lvalue foward as lvalue
b. no costly copy construction of boVector is made
*/
template <typename T> 
void relay(T&& arg)
{
    foo( std::forward<T> (arg) );
}

/* NOT SOLUTION. E.g of argument fowarding:
template <typename T> 
void relay(T arg)
{
    foo(arg);
}
*/

int main()
{
    boVector reusable = createBoVector();
    relay(reusable);           // l-value
    relay(createBoVector());   // r-value
}


/*
Reference Collapsing in C++ 11
If you see a single &, then the reduction is a single &
Only double && is reduced to && 

// Copiler can make code like this and then reduce it!

T& & -> T&
T& && -> T&
T&& & -> T&
T&& && -> T&&
*/

