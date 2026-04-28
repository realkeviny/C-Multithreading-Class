# Thread-local Data Questions

## Exercise 1: Thread-Local Variables

- ### How do thread-local variables differ from static variables?
  
  For thread-local variable, each thread can has its own copy of the object, <font color="red">and it is destroyed when the thread completes its execution</font>; For static variables, the object is shared by all threads in the program, <font color="red">and the object is destroyed until the end of program.</font>

- ### Where can we declare thread-lodal variables?
  
  I can declare it as global variables, static variables at namespace scope, data members of a class, or local variables in a function/a scope.

- ### When are thread-local variables initialized?
  
  For global variables or static variables at namespace scope, they are always initialized by the first time that they are used in a translation unit.
  
  For local variables, they are declared the first time when the thread reaches the declaration.

## Exercise 2: Thread-local Variable Example

- ### Write a program which uses thread-local variables

- ### Verify that each thread uses a different object
