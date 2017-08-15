// g++ -g this_file.cpp  
// gdb ./a.out
// b <line number of my dummy>

class SuperClass
{

};

class SubClass : public SuperClass
{

    int val;

};

int main()
{

    SubClass sub;

    //
    // Noo! This is a Slicing problem.
    //
    SuperClass super = sub;

    int dummy = 0;

}

//
// The field val from Subclass is not copied as part of the assignment
// to super!
//

//
// C++ allows this but it can often lead to crashes.
// The object is only partially there!
//
