# Livelock Questions

## Exercise 1: Livelock

- ### What is meant by the term livelock?
  
  Livelock means that a program can't make progress although it is still running.

- ### How does livelock differ from deadlock?
  
  For deadlock, the threads have stopped running, and are waiting for something which won't happen, while the threads are still active in livelock.

- ### Briefly describe a situation where livelock can occur.

        Trying to avoid deadlock, using the "try_lock()".

        <font color="red">Instead of blocking indefinitely when they cannot get a lock, the threads wait and retry.</font>

       <font color="red">If the lock is not available, the threads will retry indefinitely.</font>

## Exercise 2: Livelock Example

- ### Suggest how livelock could be avoided in your program

        Do deadlock avoidance in the correct way, like using "scoped_lock" or " lock()" to lock all the mutexes that the thread needs in a single operation.

## Exercise 3: Thread Priority

- ### What is meant by thread priority?
  
  <font color="red">A number assigned to the thread by the OS.</font>
  
  <font color="red">Higher pritority threads will be scheduled to run more often, while those with lower priority will be scheduled to run less often.</font>

- ### Does C++ support thread priority?

        No directly support, but supported by nearly every thread implementation, <font color="red">which means I can set thread priority by calling OS API</font>.

        <font color="red">The native_handle member function of the std :: thread object will return the data which is needed for this call.</font>

## Exercise 4: Resource Starvation

- ### What is meant by resource starvation?
  
  A thread can't get the resources which it needs to run, or to continue running.

- ### Give some examples

        Deadlock and Livelock.

        Lack of system resources(No new threads can be started).

        Too aggressive scheduler(This will make the low priority threads are starved of computer processor time, since the scheduler may give too much time for higher priority threads).


