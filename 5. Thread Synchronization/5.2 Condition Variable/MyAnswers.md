# Condition Variable Exercises

## Exercise 1: Condition Variable Scenario

### In the example in the video

- ### The reader thread uses std :: unique_lock.

- ### The writer thread uses std :: lock_guard.

- ### Why do the two threads use different types?
  
  For reader thread, since the "wait()" needs to unlock and lock the mutex in a flexible pattern, and only "unique_lock" can achieve this.
  
  For writer thread, it only needs to modify the data, and notify the waiting thread, "lock_guard" is more than enough,for it only needs to protect the critical section.

## Exercise 2: Condition Variable Example

- ### Now reverse the order of the threads in main()
  
  The writer thread starts first

- ### Add a sleep (say, half a second) before starting the reader thread

- ### What happens, and why?
  
  The writer thread starts early, it quickly ended modification to the data, and waking another thread up.
  
  However, when executing reader thread, the reader keeps stucking at the waiting statement.
  
  My guess: When the writer thread reaches the notify_one statement, the reader thread hasn't reached the wait() statement. <font color="red">The condition variable does not have any waiting threads to notify. The notification is "lost". So, By the time the reader thread calls wait(), the writer thread has completed
  .The condition variable does not receive any more notifications</font>




















