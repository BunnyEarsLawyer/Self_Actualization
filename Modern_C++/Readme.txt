http://en.cppreference.com/w/cpp/language/storage_duration

Interesting
- external linkage vs. internal linkeage


http://en.cppreference.com/w/cpp/concept

---------------------------------------------
std::bind
std::placeholders
- rvalue
- lvalue

The function template bind generates a forwarding call wrapper for f. Calling this wrapper is equivalent to invoking f with some of its arguments bound to args. 

bind( F&& f, Args&&... args )

- f    = Callable object (function obj, pointer to function, reference to function, pointer to member function, pointer to data member)
- args = list of arguments to bind, with the unbound arguments replaced by the placeholders _1, _2, _3... of namespace std::placeholder

Notes:
As described in Callable, when invoking a pointer to non-static member function or pointer to non-static data member, the first argument has to be a reference or pointer (including, possibly, smart pointer such as std::shared_ptr and std::unique_ptr) to an object whose member will be accessed. 

E.g.
    // (_1 and _2 are from std::placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);



---------------------------------------------
thread

- start execution immediately upon construction of the associated thread object

- starts with top-level function provided as a constructor argument.

- return value of the top level function is ignored and if it terminates by throwing an exception. std::terminate

- Top level function may communicate its return value or an exception to the caller via std::promise 

or by modifying shared variables (which may require synchronization, see std::mutex or std::atomic)


- std::thread objects may also be in the state that does not represent any thread (after default construction, detach, join)

- thread of execution may be not associated with any thread objects (after detach)


- No two std::thread objects may represent the same thread of execution.

- std::thread is not CopyConstrutible nor CopyAssignable

	- CopyConstrutible
	- CopyAssignable

- std::thread is, however, MoveConstructible and MoveAssignable

	- MoveConstructible 
        - MoveAssignable

Member classes:
	- thread.id 
Member observer functions:
	- my_thread.joinable()
	- my_thread.get_id()
	- my_thread.native_handle()           // returns underying implementation-defined thread handle
	- my_thread.hardware_concurrency()    // returns number of threads
Member operation functions:
	- my_thread.join()                    // waits for a thread to finish its execution
                                              // locks the current thread until the thread identified by *this finishes its execution. 
	- my_thread.detach()                  // permits thread to execute independently from the thread handle
	- my_thread.swap()                    // swaps 2 thread objects (std::swap)
--------------------------------------------------
thread 
C++ 11 http://en.cppreference.com/w/cpp/thread

Mutual exclusion
// algorithms that prevent multiple threads from simultaneously accesing shared resources.
// prevents data races and provides support for synchronization b/t threads

	- mutex                   // basic mutual exclusion facility
	- timed_mutex
	- recursive_mutex
	- retursive_timed_mutex
	- shared mutex            // provides shared mutual exclusion facility
	- shared timed mutex      

Generic mutex management
	- lock_guard              // std::lock_guard, http://en.cppreference.com/w/cpp/thread/lock_guard
				  // When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
                                  // When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released. 
	- shared_lock
Generic locking algorithms
Call once
Condition variables
Futures

---------------------------------------------------
std::condition_variable::notify_all  // Unblocks all threads currently waiting for *this. 


---------------------------------------------------
Atomic

std::atomic

// Atomic types are types that encapsulate a value whose access is guaranteed 
// to not cause data races and can be used to synchronize memory accesses among different threads.

Vocab
- Data races

---------------------------------------------------
Memory Model

http://en.cppreference.com/w/cpp/language/memory_model

A thread of execution is a flow of control within a program that begins with the invocation of a top-level function by std::thread::thread, std::async, or other means.

Any thread can potentially access any object in the program (objects with automatic and thread-local storage duration may still be accessed 
by another thread through a pointer or by reference).

Different threads of execution are always allowed to access (read and modify) different memory locations concurrently, 
with no interference and no synchronization requirements.

When an evaluation of an expression writes to a memory location and another evaluation reads or modifies the same memory location, 
the expressions are said to conflict. A program that has two conflicting evaluations has a data race unless

    both evaluations execute on the same thread or in the same signal handler, or
    both conflicting evaluations are atomic operations (see std::atomic), or
    one of the conflicting evaluations happens-before another (see std::memory_order) 

If a data race occurs, the behavior of the program is undefined.





































