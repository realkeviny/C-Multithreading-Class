# Questions about Unique Lock

## Exercise 1: What are the main differences between std :: lock_guard and std :: unique_lock?

1. Unique Lock has more features, but also comsumes more storage, and takes longer to perform operations compared with lock guard.

2. Even if lock guard and unique lock have the basic features of the mutex, but unique lock has some fine-grained controls, like unlock in a scope, defer locking(Instead of locking automatically at the line where unique_lock object is created, give the user rights to lock the mutex on their own as their wish), adopting a lock(avoid locking mutex again if it's already locked), checking if a mutex is locked using "owns_lock", or using try_lock().

## Exercise 2:

## We could also have avoided the problem with std :: lock_guard by writing the code like this:

```cpp
for (int i = 0; i < 5; ++i) 
{
    // Put the std::lock_guard object in an inner scope
    {
        std::lock_guard<std::mutex>lck_guard(task_mutex);
        // Critical section
        std::cout << str[0] << str[1] << str[2] << std::endl;
        // End of critical section
    } // Calls ~std :: lock_guard
    std::this_thread::sleep_for(50ms);
}
```

## Is there any advantage to using std :: unique_lock?

If I am using "std::unique_lock", I don't need to have extra inner scope , and I can control the place where I can unlock the mutex by explicitly place a call to unlock().
