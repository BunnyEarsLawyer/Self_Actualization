// $clang++ -std=c++11 this_file.cpp

#include<iostream>
#include<list>
#include<array>  // Modern std::array

// Shared Pointer = wrapper to a raw pointer
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
//  Rule of 5: 
class SharedPointer
{
    SharedPointer(int* input) 
    {
	p_count = new int;
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

    }


    ~SharedPointer()
    {
	delete p_raw;
	delete p_count; 

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

}
