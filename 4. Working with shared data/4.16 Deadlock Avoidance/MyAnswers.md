# Deadlock Avoidance Questions

## Exercise 1: Deadlock Avoidance

- ### Suggest two ways to avoid deadlock

        Viable methods

        :  Lock all the mutexes in a single operation at once.

        :  Make a hierarchy of mutexes.

## Exercise 2: Adopting Locks

- ### In the following code, why are the unique_lock objects needed when the mutexes are already locked?
  
  ```cpp
  std::lock(mut1, mut2);
  std::unique_lock<std::mutex> lk1(mut1, std::adopt_lock);
  std::unique_lock<std::mutex> lk2(mut2, std::adopt_lock);
  ```
  
  Reason: Use the mutex wrapper to manage the lock, so that the mutex can be guaranteed to be unlocked either manually(using the unlock() member function) or automatically when reaching the end of the scope.

- ### Rewrite this code to use std :: unique_lock's defer_lock option






