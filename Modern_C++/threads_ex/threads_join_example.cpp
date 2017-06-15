#include <iostream>
#include <thread>
#include <chrono>

// VERY IMPORTANT, how to compile: 
// Use c++11
// Use threads
// $g++ -pthread -std=c++11 blah_example.cpp

//
// Joining a thread makes one thread of execution wait for another thread to finish running.
// 
 
void foo()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
 
void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
 
int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);
 
    std::cout << "starting second helper...\n";
    std::thread helper2(bar);
 
    std::cout << "waiting for helpers to finish..." << std::endl;
    helper1.join();
    helper2.join();
 
    std::cout << "done!\n";
}
