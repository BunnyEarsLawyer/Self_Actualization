
#include <iostream>

using namespace std;

// Foo and Bar are a common placeholder names in computer programming

class Foo
{

public:
    Foo() { cout << "Foo's constructor" << endl; }

};

//
// Bar inherits from Foo
// 
class Bar : public Foo
{

public:
    Bar() { cout << "Bar's constructor" << endl; }

};

int main()
{
    Bar bar;
}
