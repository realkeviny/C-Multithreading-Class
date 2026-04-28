# Shared Mutexes Exercises

## Exercise 1: Shared Mutex

### Explain briefly what a shared mutex is

This is an mutex that can be locked using 2 methods.

I can either let the thread takes an exclusive lock to lock this mutex, which means that no other threads can enter the critical section which is protected by this mutex, executing by the thread which owns the exclusive lock, and more importantly, they can' acquire any type of lock.

Or I can give a thread a shared lock to lock it, so that other threads can also take a shared lock, and execute the code in their critical sections which is protected by shared mutex.

While there is a thread got a exclusive lock, other threads have to wait until this thread has releases ut lock. For a thread/threads which have the shared lock, a thread which want the exclusive lock must wait until these batch of threads released their shared locks.

## Exercise 2: Shared Mutex Usage

### Write a program which has two task functions

- A "writer" task which modifies shared data

- A "reader" task which accesses shared data but does not modify it 

### Use an std :: shared_mutex to synchronize these tasks

- The reader task should sleep for 100ms before unlocking the mutex 

- This is to simulate activity 

### The program creates twenty reader threads, then two writer threads, then another twenty reader threads

### How long do you expect it will take the program to run?

About 2 seconds.

### Explain the results

Actually, the program only takes 1 second to finish the program.

Because of the shared lock acquired by reader threads, the first 20 readers can execute concurrently and safely.

And after the locks for those 20 are destructed, the writer threads take the exclusive lock, and execute the critical sections in writer task function, which will block the second batch of reader threads to get the shared locks.

Then the last 20 reader threads take shared locks, readers execute concurrently and  safely.

If I am using std::mutex, the program will run sequentially, which takes 4~5 seconds.

## Data Race Avoidance

### Explain how using a shared mutex avoids data races

| Reader Aspect                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | Writer Aspect                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| For reader threads, they can't acquire their shared lock while there are other threads with exclusive locks executing their critical section.                                                                                                   When there is no thread which has a exclusive lock on the mutex, the reader thread will get its shared lock, lock th e mutex, and execute its critical section. During this procedure, other reader threads are allowed to acquire their shared locks, and the writer threads have to wait to acquire their exclusive locks. Until last batch of reader threads have ended the execution of critical section and unlock the mutex. | For writer thread, it can't acquire its exclusive lock while their are other threads with exclusive locks or shared locks executing their critical section.                                                                                When there is no thread which has a lock on the mutex, the writer thread will get its exclusive lock, lock the mutex, and execute its critical section. During this procedure, other writer threads are not allowed to acquire their exclusive locks, and the reader threads also can't acquire their shared locks. Until current writer thread has ended the execution of critical section and unlock the mutex. |

While the reader threads are executing the critical section, no other writer threads are interleaving reading actions, vice versa. Because reader threads won't modify anything. Eventually Data race has been avoided.


