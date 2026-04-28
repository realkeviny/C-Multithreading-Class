# Lazy Initialization Questions

## Exercise 1: Lazy initialization

- ### What is meant by lazy initialization?
  
  It means "A variable is only initialized when it's firstly used".
  
  <font color="red">"eager" initialization: a variable is initialized when it is
  declared.</font>

- ### Give an example of a situation where lazy initialization could be useful
  
  Constructing an expensive object(Like a string).

## Thread-safe Lazy Initialization

- ### Is lazy initialization safe to use in multi-threaded code?

        Yes, after the mutex is added, if it has been locked before I do anything revolves around modifying the variable. It can be ensured that only 1 thread will actually need to be locked, for it will initialize the variable, while the rest only use it, so they don;t need to be locked(Loss of efficiency).


