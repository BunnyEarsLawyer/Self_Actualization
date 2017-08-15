
#include <iostream>

using namespace std;

//
// The superclass constructor runs first to initialize all fields
// This ensures that the subclass may use the fields in the superclass
// All done for you by the compiler
// Similarly, the destructor for the superclass will be called automatically
//

class FooSuperClass
{

public:

    FooSuperClass() { cout << "FooSuperClass's constructor" << endl; }

    FooSuperClass( const string& val ) 
    { cout << "FooSuperClass's non-default constructor" << endl; }

    ~FooSuperClass() { cout << "FooSuperClass's destructor" << endl; }

};

//
// Bar inherits from FooSuperClass
// 
class Bar : public FooSuperClass
{

public:
    Bar() 
    // 'initialization list'
    : FooSuperClass( "arg" ) 
    { cout << "Bar's constructor" << endl; }

    ~Bar() { cout << "Bar's destructor" << endl; }

};

int main()
{
    Bar bar;
}
