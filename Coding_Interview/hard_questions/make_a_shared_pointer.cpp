// $clang++ -std=c++11 this_file.cpp

#include<iostream>

// Shared Pointer = wrapper to a raw pointer

// Notes:
// Rule of 5: If you need one, you need the others
// 1) Destructor, 2) Copy Constructor, 3) Copy Assignment Operator
// 4) Move Constructor or 5) Move Assignment Operator 

// The compiler default copy constructor only makes a 'shallow copy' = only minimum copied
// E.g. https://stackoverflow.com/questions/3278625/when-do-we-have-to-use-copy-constructors
// If a class has a c-style array, only the pointer to the array is copied, not the buffer.
// This shallow copy is member-wise coping

// In order to count the number of objects created in C++
// use CRTP: 'Curiously Recurring Template Pattern'
// https://stackoverflow.com/questions/1926605/how-to-count-the-number-of-objects-created-in-c++

class SharedPointer
{
public:
    // Constructor
    SharedPointer(int* input) 
    {
	p_count = new int;
	(*p_count)++;
	p_raw = input;
    }
    //
    // Copy Constructor
    //
    // Input: pass by reference a const of the class itself!
    // You need const to protect to_copy, so you don't override anything
    // Output: None, it's a constructor :) 
    SharedPointer(const SharedPointer& to_copy)
    {
    	p_count = to_copy.p_count;
        p_raw = to_copy.p_raw;
    }
    //
    // Assignment operator (operator=) 
    //
    // Input: pass by reference a const of the class itself!
    // Output: Address of the SharedPointer, a reference 
    SharedPointer& operator= (const SharedPointer& to_copy)
    {
        // Make sure we aren't assigning to ourselves
        // Check the object on the right doesn't have the same address
        // If it does, just return us. 
	if(this == &to_copy)
	{
            // 
            // Every object in C++ has access to its own address 
            // through an important pointer called 'this' pointer.
            // to dereference it, use *this. 
	    return *this;
	}

        // Use: my_object = other_object;
        // First free up old memory before over-writting new values
	delete p_raw;
	delete p_count; 
	p_raw  = nullptr;
	p_count = nullptr;

        // Populate my member variables with the ones from the other one to copy
        p_raw = to_copy.p_raw; 

        (*(to_copy.p_count))++;

        p_count = to_copy.p_count; 


	// We have copied the right hand side obj! Return the address of this object
        return *this;
    }

    // Destructor 
    ~SharedPointer()
    {
        if(p_count > 0){ (*p_count)--; }
	delete p_raw;
	delete p_count; 
    }

    int get_pointer_value() 
    {
	return *p_raw;
    }

    void print_all_shared_pointer_status() 
    {
        std::cout << "raw value: " << *p_raw << std::endl;
        std::cout << "count of shared pointers: " << *p_count << std::endl;
	
    }

    private:
        int *p_raw;
        int *p_count;

};


int main()
{
    /*
    int * integer = new int;
    {
        shared_ptr<int> shared_ptr_1(integer);
        {
            shared_ptr<int> shared_ptr_2(shared_ptr_1);
            shared_ptr<int> shared_ptr_3 = shared_ptr_1;
    
        } // shared_ptr_2 and shared_ptr_3 go out of scope, integer not deleted
    }
    */

    std::cout << "hi" << std::endl;

    // allocates memory for the int data type from the 'free store'
    // 'free store' = https://stackoverflow.com/questions/1350819/c-free-store-vs-heap
    // new/delete  -> use the free-store 
    // malloc/free -> use the heap
    int* p_integer = new int;

    *p_integer = 9; 

    std::cout << "My new raw integer " << *p_integer << std::endl;

    //Constructor 
    SharedPointer shared_ptr_A(p_integer); 

    std::cout << "A points to " << shared_ptr_A.get_pointer_value() << std::endl;

    shared_ptr_A.print_all_shared_pointer_status();

    //Copy Constructor
    SharedPointer shared_ptr_B(shared_ptr_A);

    std::cout << "B points to " << shared_ptr_B.get_pointer_value() << std::endl;

    *p_integer = 10; 

    // Scope
    {

        //Assignment Operator
    	SharedPointer shared_ptr_C = shared_ptr_A; 

        shared_ptr_A.print_all_shared_pointer_status();
        shared_ptr_B.print_all_shared_pointer_status();
        shared_ptr_C.print_all_shared_pointer_status();
        std::cout << "A points to " << shared_ptr_A.get_pointer_value() << std::endl;
        std::cout << "B points to " << shared_ptr_B.get_pointer_value() << std::endl;
        std::cout << "C points to " << shared_ptr_C.get_pointer_value() << std::endl;

    } // shared pointer C goes out of scope


}
