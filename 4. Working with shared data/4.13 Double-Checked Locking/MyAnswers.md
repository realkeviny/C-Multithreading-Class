# Double-checked Locking Questions

## Exercise 1: Double-checked locking

### What is meant by double-checked locking? Explain how it is intended to work

    Double-checked locking is a programming pattern to <font color="red">perform thread-safe lazy initialization while avoiding unnecessary locking</font>

   This pattern works like:

1. Check the variable, if the variable is uninitialized, lock the mutex(<font color="red">ensures that the mutex is only locked if the variable is
   uninitialized</font>)

2. Check the variable again, if it's still remain uninitialized, initialize the variable(<font color="red">make sure that another
   thread has not initialized the variable while this thread was interrupted</font>).

3. Unlock the mutex.

4. Use it(For other threads, if the variable is already initialized, they will just use the variable).

## Exercise 2: Double-checked locking issues

### What issues can arise with double-checked locking in C++?

    A potential race condition: There could be a thread which interleaves between checking the variable and locking the mutex.

    In addition, before C++ 17, the order of operations initializing variable is not guaranteed, which means it can be in any order.

    A tangible example is that initializing variable involves memory allocation, initialization, then store the address of this memory in the pointer variable.

    But, before C++ 17, the address of the memory may be stored in the pointer variable before initializing the memory(/constructing the object), which will lead to a bad result: another thread may see the variable "initialized", while the previous one has been interrupted, so the other thread will jump over the lock, and the second check, then use the uninitialized object.

### Describe some ways to avoid these issues

1. Use the mutex naively.

2. Use std::call_once() to ensure that the thread which will initialize the variable won't be interrupted(/<font color="aqua">ensure that the
   initialization code is only executed once, by one thread, which will not be interrupted</font>)

3. Use a C++ 17 compiler, for the order of compilation has been tightened in C++ 17, the object is guaranteed to be constructed before the address goes to the pointer variable.

4. Refer to Meyer's Singleton

                    
