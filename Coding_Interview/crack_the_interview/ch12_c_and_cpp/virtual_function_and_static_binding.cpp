// How to build: $clang++ -std=c++11 hello_world.cpp
// 
// Virtual functions, static binding. See main() 
// 

// Abstract class:
// Another use of virtual functions is when you don't want to 
// implement a method for the parent class.
// E.g. Student and Teacher both use addCourse()
// and both inherit from Person, but Person doesn't use addCourse()
// Hence, we add addCourse() to be a virtual function in Person
// Adding a 'pure virtual function' makes Person an abstract class. 
// Vocab: pure virtual, abstract class

#include<iostream>

// macro
#define NAME_SIZE 50

class Person 
{

    int id; // all members private by defaul
    char name[NAME_SIZE];
    Person(int a);

public:
    void aboutMe() 
    { 
        std::cout << "I am a person.";
    }
}
//
// The initialization list, data member id 
// is assigned before the actual object is created!
// This is necessary if the fields are constant or class types
//
Person::Person(int a) : id(a)
{
}

// ###########################

class Student : public Person
{
public:
    void aboutMe() 
    { 
        std::cout << "I am a student.";
    }
};

// ###########################

int main()
{
    // Normally:
    Student * p = new Student();
    p->aboutMet();
    delete p;
    // What if we use the parent class?
    Person * p = new Student();
    p->aboutMet();
    //
    // "I am a person" prints b/c aboutMe() is resolved at compile time
    // This is called 'static binding'
    // If you want "I am a student" you must add the keyword 'virtual'
    // to the Person class's aboutMe() 
    // E.g. class Person { virtual void aboutMe(); ...
    //
    return 0;
}
