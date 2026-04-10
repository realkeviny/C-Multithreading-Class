# Mutex Introduction Questions

## Explain what is meant by the term "mutex"

1. Shorthand for "Mutual Exclusive Object", mainly used for excluding threads from the critical section. It can ensure that only 1 thread can access codes in critical region at a time. 

2. A mutex can only be locked once.

3. With mutex, We can not only enforce that only 1 thread can enter the critical section at a time, but also do synchronization between threads, so there will be no data race.

## How can mutexes be used with critical sections?

1. The threads will be synchronnized, so that when a thread is executing codes in critical section, no other threads can interleave the execution, but just execute in turn.

2. When the mutex is unlocked, any changes that were done in critical section by previous threads will be visible to other threads.
