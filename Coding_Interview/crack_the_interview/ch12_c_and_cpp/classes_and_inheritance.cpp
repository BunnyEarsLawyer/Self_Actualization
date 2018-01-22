// How to build: $clang++ -std=c++11 hello_world.cpp
// 
// Inheritance 
// 
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
    Student * p = new Student();
    p->aboutMet();
    delete p;
    return 0;
}
