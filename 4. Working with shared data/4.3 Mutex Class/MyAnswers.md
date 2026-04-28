# Mutex Questions

## Assignament 01: Briefly describe the C++ std::mutex

This class is offered in C++ 11, <font color="red">implemented the mutual exclusive object</font>, I can create objects of this class to synchronize threads. 

<font color="red">Has 3 member functions, lock(), try_lock(), and unlock(). </font>

- <font color="red"> lock(): Will try to lock the mutex, and won't return until succeeds, which means it will wait until it locks the mutex successfully if can't lock the mutex now.</font>

- <font color="red">try_lock(): Will also try to lock the mutex, but it will return immediately even if it failed to lock the mutex because of occupation.</font>

- <font color="red">unlock(): Unlock the mutex.</font>

## Assignment 04(Based on 03): What do you observe?

When task1 locks the mutex, the try_lock() in task2 will fail to locks the mutex,
and return false.
When task1 unlocks the mutex, the try_lock() in task2 will lock the mutex successfully, and the code  in task2 can go on.



Task1 is about to lock the mutex...
Task1 locked the mutex...
Task2 is about to lock the mutex...
Task2 is waiting to Lock the mutex...
Task2 is waiting to Lock the mutex...
Task2 is waiting to Lock the mutex...
Task2 is waiting to Lock the mutex...
Task 1: Locked the mutex!
Task1 is about to unlock the mutex...
Task 2: Finally got the lock!
Task2 is about to unlock the mutex...
All tasks finished.