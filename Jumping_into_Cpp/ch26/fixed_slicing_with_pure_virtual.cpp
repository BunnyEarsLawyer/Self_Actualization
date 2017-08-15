// DOES NOT COMPILE

// g++ -g this_file.cpp  
// gdb ./a.out
// b <line number of my dummy>

// Another way to fix slicing is to make the SuperClass
// have at least one pure virtual function.

class SuperClass
{

   //
   // Declare the copy constructor for this class private
   // and don't implement it. This fixes slicing
   //
public:

   //
   // Since we declare a copy constructor you need to define 
   // your own default constructor
   //
   SuperClass() {}

private:

   //
   // Copy constructor, we will not define this method. Prohibited.
   // E.g. Object my_object_1(my_object_2); 
   //
   SuperClass (const SuperClass& other);

   virtual void pure_virtual_function() = 0; 

};

class SubClass : public SuperClass
{

public:

   SuperClass() {}

   int val;

};

int main()
{

    SubClass sub;

    //
    // THIS LINE CANNOT BE CALLED B/C 
    //  OF THE VIRTUAL FUNCTION IN SUPERCLASS 
    //

    // SuperClass super;


    //
    // However, you can still write this...
    // pg 396 I need to fix sub
    //

    SuperClass *super = & sub;

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
