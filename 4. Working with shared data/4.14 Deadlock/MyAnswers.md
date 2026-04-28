# DeadLock Exercises

## Exercise 1: Deadlock

- ### Explain what is meant by deadlock
  
  Deadlock means " A thread can't proceed with executing its code, because of some problem."
  
  Usually, it refers to a situation of "mutual deadlock", which means "2 or more threads are preventing each other from running."

- ### Give an example of how deadlock can occur
  
  There are 2 threads and two mutexes.
  
  Thread A locks the mutex 1, and thread B locks the mutex 2.
  
  Now, thread A wants to lock the mutex 2, but it has to wait until thread B unlocks it.
  
  At the same time, thread B wants to lock the mutex 1, but it has to wait until thread A unlocks it.
  
  Each thread is waiting for the other thread to unlock its mutex.

- ### Suggest a way to avoid deadlock

        Make the threads try to lock the mutexes in the same order.


