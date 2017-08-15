// g++ -g this_file.cpp  
// gdb ./a.out
// b <line number of my dummy>

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

};

class SubClass : public SuperClass
{

    int val;

};

int main()
{

    SubClass sub;

    //
    // THIS LINE NOW CAUSES A COMPILER ERROR
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
