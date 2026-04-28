# Shared Data Initialization Questions

## Exercise 1: Shared Data

- ### Give a list of all the ways to create shared data in C++
  
  There are a number of ways to create shared data:
  
  1. Global Variable(Accessible by any code in the program)
     
     Code Example:  
     
     ```cpp
     int dog_count{0}; // Global scope
     
     void do_sth()
     {
         ++dog_count;
     }
     
     int main(int argc, char *argv[])
     {
         do_sth();
         return 0;
     }
     ```
  
  2. Static Variable at namespace scope(Accessible by any code which can see the declaration).
     
     Code Example:
     
     ```cpp
     namespace FunctionUse
     {
         static int catCount{3};
     }
     ```
  
  3. Static class member(If the class has member functions which access that static member, then it can be accessed by any code which calls these member functions(including constructors);If the class member has public accessibility, then any code which can see the class definition will be able to access it.)
  
         Code Example:
  
  ```cpp
  class Point
  {
  private:
      double m_x;
      double m_y;
      static size_t m_point_count;
  
  public:
       //Other Functions...
  };
  ```
  
  4. Local variable which is declared static(Accessible to any code which calls the function)
     
     Code Example:
     
     ```cpp
     unsigned add_student()
     {
         static unsigned student_count{0};
     
         student_count++;
         return student_count;
     }
     ```

- ### How are these shared data variables initialized?
  
  For Global Variables, Static Variable at namespace scope, Static class members,  they are all initialized when the program starts up, before the main() function is called. 
  
  For Local variable which is declared static, it will be initialized the first time the program reaches the declaration.

- ### Does these initialization procedures have any implications for thread safety?

        For Global Variables, Static Variable at namespace scope, Static class members,         they are all initialized when the program starts up, before the main() function,         there is only 1 thread running, the conditions of data race aren't satisfied.

        For Local variable which is declared static, if there are multiple threads using the         function of it, it's inevitable that some threads may call the constructor of the         static object concurrently, which is a situation of data race.

## Exercise 2: Static Local Variable Initialization Before C++ 11

- ### Before C++11, could static local variables be initialized in a thread-safe way?
  
  No.
  
  Usually, we can lock a mutex using the implementation from 3rd party library. However, The mutex has to be locked every time the program passes through that declaration, which is very inefficient.

## Exercise 3: Static Local Variable Initialization in C++ 11

- Has the initialization of static local variables changed in C++11?
  
  Yes, the behavior has been standardized and well-defined. Threads are all synchronized internally by the implementation, without data race.
  
  Now, only 1 thread will be able to initialize the variable. If any other thread reaches that declaration, it will be blocked, and must wait until the first thread has finished initializing the variable, then the second thread will use the initial value that the first thread gave to it. So that, all threads will see this variable as having the same initial value.

- What happens if the variable is modified after initialization?
  
  The static variable will turn back to shared data which need protection from data race.

## Exercise 4: Classic Singleton Implementation

- What is meant by a Singleton class?
  
  A type of class which can only have a single instance, this pattern is generally used for creating global objects.

- Briefly describe the traditional implementation of a Singleton class.
  
  1. Make the constructor private.
  
  2. Delete the copy and move constructors, so that no more objects of this class will be created.
  
  3. A static data member which holds the instance, and a static member function which returns it.

- Implement a traditional Singleton class.

- Write a multi-threaded program to test it.

- Is the traditional Singleton thread-safe?
  
  No. 
  
  Result:
  
  Traditional Singleton Object Created!
  000002A6D3E79C40
  Traditional Singleton Object Created!000002A6D3E79C40
  000002A6D3E79C40
  
  000002A6D3E79600
  Traditional Singleton Object Created!
  000002A6D3E79600
  000002A6D3E79C40
  Traditional Singleton Object Created!
  000002A6D3E7A240000002A6D3E7A240
  000002A6D3E79600
  000002A6D3E79840
  000002A6D3E79840
  Traditional Singleton Object Created!
  000002A6D3E79CC0
  000002A6D3E79C40
  
  000002A6D3E79C40
  Traditional Singleton Object Created!
  000002A6D3E79840
  000002A6D3E7A380
  000002A6D3E79600
  000002A6D3E79C40
  000002A6D3E79840
  000002A6D3E79840
  
  Apparently,  <font color="red">Threads can concurrently access the static pointer member, and they can modify the static pointer member.</font>

## Exercise 5: C++11 Singleton Implementation

- Does C++11 give us a better way to implement the Singleton?
  
  C++ 11 guarantees that static local variable's initialization is thread-safe.

- Implement a Singleton class which uses these features

- Write a multi-threaded program to test your class
