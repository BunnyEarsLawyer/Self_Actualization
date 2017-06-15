#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

// VERY IMPORTANT, how to compile: 
// Use c++11
// Use threads
// $g++ -pthread -std=c++11 shared_pointer_example.cpp -o shared_pointer

//
// std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. 
// It may own the same object. 
// Memory dealllocated and object destroyed when 
// 1. last remaining shared_ptr owning the object is destroyed
// 2. last remaining sharned_ptr owning te object assigned another pointer via operator= or reset()

// CopyConstrutible
// CopyAssignable
// LessThanComparable
// Contextually convertible to bool

// All member functions, including copy constructor and copy assignement can be 
// called bymutiple threads on different instances of shared_ptr w/out additional synchronization.

// Base class structure (?) 
struct Base
{
    Base() 
    { 
	std::cout << "  Base::Base()\n"; 
    }
    // Note: non-virtual destructor is OK here
    ~Base() 
    { 
	std::cout << "  Base::~Base()\n"; 
    }
};
 
// Derived class structure (?) 
struct Derived: public Base
{
    Derived() 
    { 
	std::cout << "  Derived::Derived()\n"; 
    }
    ~Derived() 
    { 
        std::cout << "  Derived::~Derived()\n"; 
    }
};

//Thread 
// Input: shared pointer to a Base struct
void cool_thread(std::shared_ptr<Base> p)
{
    // Makes thread sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //
    // A piece of code is 'thread-safe' if it functions correctly during simultaneous execution by multiple threads. 
    // In particular, it must satisfy the need for multiple threads to access the same shared data, and the need for 
    // a shared piece of data to be accessed by only one thread at any given time.
    // A.K.A local pointer in a thread
    //
    std::shared_ptr<Base> lp = p; // thread-safe, even though the
                                  // shared use_count is incremented
    {
	//
        // The 'mutex' class is a synchronization primitive that can be used to protect shared data from being simultaneously 
        // accessed by multiple threads. 
	//
        // 'static' or thread storage duration and 'internal linkage' 
        static std::mutex io_mutex;

        //
        // The class 'lock_guard' is a mutex wrapper that provides a convenient 'RAII-style' mechanism for 
        // owning a mutex for the duration of a scoped block. 
        //
        std::lock_guard<std::mutex> my_lock_guard(io_mutex);

        //
        // In a typical implementation, std::shared_ptr holds only two pointers:
	// 1. the stored pointer (one returned by get());
        // 2. a pointer to 'control block'. 
        std::cout << "local pointer in a thread:\n"
                  << "  lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';

	// The 'control block' is a dynamically-allocated object that holds:
	//    either a pointer to the managed object or the managed object itself;
	//    the deleter (type-erased);
	//    the allocator (type-erased);
	//    the number of shared_ptrs that own the managed object; 
	//    the number of weak_ptrs that refer to the managed object. 

    }

}
 
int main()
{
    // Makes a Base shared pointer to a ... shared Derived structure
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';
    //
    // 3 threads created with the same inputs 
    // In: function cool_thread
    // In: shared pointer 
    // The class 'thread' represents a single thread of execution. Threads allow multiple functions to execute concurrently. 
    //
    std::thread t1(cool_thread, p), 
                t2(cool_thread, p), 
                t3(cool_thread, p);

    //
    // 'reset' replaces the managed object 
    //
    p.reset(); // release ownership from main

    std::cout << "Shared ownership between 3 threads and released\n"
              << "ownership from main:\n"
              << "  p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';

    //
    // 'join'  waits for a thread to finish its execution 
    // 
    t1.join(); 
    t2.join(); 
    t3.join();

    std::cout << "All threads completed, the last one deleted Derived\n";

}

