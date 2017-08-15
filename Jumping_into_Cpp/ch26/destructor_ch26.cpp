
#include <iostream>

using namespace std;

//
// The superclass constructor runs first to initialize all fields
// This ensures that the subclass may use the fields in the superclass
// All done for you by the compiler
// Similarly, the destructor for the superclass will be called automatically
//

// Foo and Bar are a common placeholder names in computer programming

class Foo
{

public:
    Foo() { cout << "Foo's constructor" << endl; }
    ~Foo() { cout << "Foo's destructor" << endl; }

};

//
// Bar inherits from Foo
// 
class Bar : public Foo
{

public:
    Bar() { cout << "Bar's constructor" << endl; }

    ~Bar() { cout << "Bar's destructor" << endl; }

};

int main()
{
    Bar bar;
}
