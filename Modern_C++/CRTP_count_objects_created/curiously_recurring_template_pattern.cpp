#include<iostream>

// Template Class
template <class T>
class Counter
{
  private:
      static int count;
  public:
    Counter()
    {
       count++;
    }  
    Counter(const Counter &c)
    {
       count++;
    }   
    ~Counter()
    {
       count--;
    }    
    static int GetCount() {

         return count;
    }
};

template<class T> 
int Counter<T>::count = 0; 


// Count these classes, they inherit from template
class MyClass : private Counter<MyClass>
{
   public:
      using Counter<MyClass>::GetCount;
};

int main()
{

    MyClass a;
    int count = a.GetCount();
    std::cout << count;
}
