# Exercise 1: Member Functions for Atomic Types

## All atomic types have the following member functions

## Describe each of these member functions

- store()
  
  Atomically replace the atomic object's value with the argument I pass.

- load()
  
  Atomically return the current value of the object.

- exchange()
  
  Atomically replace the atomic object's value with the argument I pass, but will return the old value it stores.

# Exercise 2: std::atomic_flag

## Briefly describe the std :: atomic_flag class

This is a class which represents an atomic bool type. It's simpler and has less overhead compared with bool specializetion of atomic template(std::atomic<bool>), and can be use to implement a spinlock.

It has 3 operations, an assignment operator, a test_and_flag() member function to set the flag to true and return the old value, and a clear() to set flag to false.

It must be initialized to false.


