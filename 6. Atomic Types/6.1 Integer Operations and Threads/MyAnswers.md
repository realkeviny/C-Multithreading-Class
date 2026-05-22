# Exercise 1: Integer Operation Example

## 1. Briefly explain my results

        There is a data race. The reason is that despite increment(++) operation on an integer is a operation the can't be interrupted in a thread, but incrementing a variable takes 3 steps: Pre-fetch the value, increment, and publish the new value. That means other threads can interleave between these operations without synchronization, and some situations like using an out-of-date value because another thread changed the value after the thread has fetched it, or there may be a thread overwrite the result that other threads published(/<font color="red">Another thread could publish its value before this thread does. Our thread will publish a stale value to other threads</font>).

# Exercise 2: Thread Synchronization

## 2. Briefly explain how using a mutex avoids these problems

Locking the mutex before the increment operation. When the mutex is locked, no other threads can access this value and change it after current thread has fetched it.

Unlocking the mutex means that the new result is published, and is available for other threads to use.




