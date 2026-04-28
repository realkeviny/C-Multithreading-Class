# Timeouts and Mutexes Questions

## Exercise 1: std::recursive_mutex

- ### Briefly describe std :: recursive_mutex
  
  This is a type of mutex which can be locked repeatedly in the same thread. However, if I am about to unlock it, I have to call "unlock()" for each call of its lock(). 

- ### Is this a feature that programmers should use regularly?

        No, if I think I need this, it probably means I have made a mistake while designing         the program. <font color="red"> Except for recursive programs. </font>

        <font color="red">If there is a possibility that a mutex may be locked more than once, this usually indicates a problem with the design of the code.</font>

## Exercise 2: std::timed_mutex

- ### Briefly describe std :: timed_mutex
  
  A mutex that <font color="red">wait with a timeout to acquire a lock on the mutex.</font>
  
  It added 2 member functions compared to std::mutex, try_lock_for() and try_lock_until().
  
  For try_lock_for(), I can give it a duration argument, then it will try to lock the mutex. If it can't lock the mutex within the given duration, it will return false.
  
  Otherwise, return true.
  
  Conversely, for try_lock_until(), I can give it a specific time point argument, then it will try to lock the mutex. If it can't lock the mutex by the time point, it will return false.
  
  Otherwise, return true.

        <font color="B0e0e6">Precisely:try_lock_for() will wait until a certain time interval elapses to acquire a lock.
        try_lock_until() will wait until a certain time point to acquire a lock.</font> 

              

- ### Is there another way to obtain this functionality?
  
  <font color="red">std::unique_lock() has added the same member functions, and can be called using any type of mutex as the lock's parameter.</font>

## Exercise 3: try_lock_for() and try_lock_until()

- ### Rewrite the try_lock program from "Mutex Introduction" to use (Done)
  
   try_lock_for() with std :: timed_mutex
  
   try_lock_until() with std :: timed_mutex
  
   try_lock_for() with std :: unique_lock
  
   try_lock_until() with std :: unique_lock

- ## What do you observe?

        Nearly same results.
