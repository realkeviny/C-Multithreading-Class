## Exercise 1: Asynchronous Programming

## What is the difference between starting a synchronous task and starting an asynchronous task?

Starting a synchronous task will block the current task until the synchronous task is finished, then the current task can continue to perform any more operations.

Starting an asynchronous task won't block the current task, which means the current task can keep working, and the new task will run in background.

# Exercise 2:  Advantages of Asynchronous Programming

## What advantages does asynchronous programming have?

1. The current task can continue to do other useful work while the asynchronous operation is being processed, as long as the other work doesn't depend on the task/data.

2. In case of getting to a point where dependant for current thread, I can block(Maybe I don't need to).

3. Better throughput and more user satisfaction.



# Blocking and Multi-threading Programs

## Why is blocking undesirable in threaded programs?

1. Slow down threads.

2. Any threads which join with a thread which is blocked will also be blocked themselves.

3. <font color="red">In</font> a critical section, any other threads which wait to enter this section will be blocked for longer than actually needs. In addition, deadlock may occurs if used multiple locks/mutexes.



# Blocking and Non-blocking Operations

## What is meant by a blocking operation, in a multi-threaded program?

Blocking operation is an operation that will cause a thread to stop and wait, until the operation is complete(Like locking a mutex/performing an atomic operation)

## Briefly explain how asynchronous programming can be used to avoid blocking operations

We mainly use message queue to avoid it, the threads which want to have tasks processed will push the messages onto the queue,<font color="red">instead of performing an operation directly.</font>There's another thread which will take the messages off the queue, and process the tasks. Meanwhile, the threads which pushed the messages(the original threads) can continue running without waiting for the completion.




