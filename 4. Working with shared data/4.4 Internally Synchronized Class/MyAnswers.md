# Internally Synchronized Class Exercises

## Exercise 1: Explain the terms "internal synchronization" and "external synchronization"

Internal Synchronization: Wrap key moves into wrapper functions with mutexes to ensure there is no data race. The user doesn't need to do any extra thing before acting.

External Synchronization: Every time before doing an action which may cause data race , the user must lock manually and then do the rest.

## Exercise 2: Wrapper for std::vector

- Is std :: vector an internally synchronized class?

        No. All C++ containers need external synchronization.

- How can we provide internal synchronization for std::vector?
  
  A typical way is to write a wrapper class for the std::vector, which consists of a mutex data member, a vector data member, and wrappers to desired actions.

- Implement your proposed solution and test it(See Assignment.cpp)
