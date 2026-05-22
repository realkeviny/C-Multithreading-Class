# Exercise 1: Programming with locks

- ## Briefly describe some of the disadvantages of programming with mutexes and locks
  
  1. If I forgot to lock, or used the wrong mutex, then race conditions may occur.     
  
  2. If I lock one mutex, and then try to lock another mutex in the same thread without unlocking the first mutex, then I have a risk of deadlock(Lack of composability).
  
  3. High overhead(It's time-consuming while locking and unlocking mutexes).
  
  4. Lack of scalablity bacause of coarse-grained locking.
  
  5. Increased complexity and increased overhead because of too fine-grained locking.

# Exercise 2: Lock-free Programming

## What is meant by a lock-free program?

It's a program that threads can execute critical sections concurrently, without the need of blocking the threads.

## Briefly list some of the advantages of lock-free programming

1. Threads will never block each other, so there's no possibility of deadlock/livelock.

2. If a thread is blocked, other threads will be able to continue to execute, which is especially useful if work must be completed with in a fixed time limit.

## Briefly list some of the disadvantages of lock-free programming

1. Very difficult to write code which is efficient and correct enough.

2. Unsuitable for many applications.

3. <font color="red">Programs can be hard to understand, with very subtle bugs</font>
