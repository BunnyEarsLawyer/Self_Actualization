#include<iostream>

struct range
{
    int a;
    int b;
};


bool is_connected(const range & x, const range & y)
{

    // if y.a is between (x.a, x.b) or if y.b is between(x.a, x.b) inclusive
    if( ( (y.a >= x.a) && (y.a <= x.b) ) | ( (y.b >= x.a) && (y.b <= x.b) ) )
    {
        return true;
    }
    // if x.a is between (y.a, y.b) or if x.b is between(y.a, y.b) inclusive
    if(( (x.a >= y.a) && (x.a <= y.b) ) | ( (x.b >= y.a) && (x.b <= y.b) ) )
    {
        return true;
    }

    return false;

}
// Find all non connecting ranges.
int main()
{
    std::cout << "hi";

    range X;
    range Y;

    X.a = 3;    X.b = 4;
    Y.a = 2;    Y.b = 5;
    std::cout << "connected? " << is_connected(X,Y) << "\n";

    X.a = 2;    X.b = 5;
    Y.a = 3;    Y.b = 4;
    std::cout << "connected? " << is_connected(X,Y) << "\n";

    X.a = 2;    X.b = 3;
    Y.a = 3;    Y.b = 4;
    std::cout << "connected? " << is_connected(X,Y) << "\n";

    X.a = 2;    X.b = 3;
    Y.a = 20;    Y.b = 24;
    std::cout << "connected? " << is_connected(X,Y) << "\n";

}
