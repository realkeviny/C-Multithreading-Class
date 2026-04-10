# Mutex Introduction Questions

## Explain what is meant by the term "mutex"

1. Shorthand for "Mutual Exclusive Object", mainly used for excluding threads from the critical section. It can ensure that only 1 thread can access codes in critical region at a time. 

2. A mutex can only be locked once.

3. With mutex, We can not only enforce that only 1 thread can enter the critical section at a time, but also do synchronization between threads, so there will be no data race.

## How can mutexes be used with critical sections?

A thread locks the mutex when it enters the critical section.

When the thread is about to leave the critical section, it will unlock the mutex, allowing other threads to execute codes in critical section.

If the mutex is locked by a thread, no other threads are allowed to enter the critical section, they have to wait until the mutex has been unlocked.

These steps ensures that the threads are synchronized, a thread won't be interleaved while executing the codes in critical section, and data race has been avoided.
