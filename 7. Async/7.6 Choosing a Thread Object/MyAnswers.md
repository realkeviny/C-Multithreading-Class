# Exercise 1: Choosing a Thread Object

## What options does C++ provide for starting a task?

Create a std::thread object.

Create a std::packaged_task object.

Call std::async()

## Give the advantages and disadvantages of each one

std::thread : 

As the most flexible method, it allows me to access the underlying implementation on the OS, so I can do things like "Setting the thread priority or pinning a task to a specific core". In addition, I can detach the thread, and let it run in the background, without having to wait for the result.

std::packaged_task :  

This is the best choice if I want to represent tasks as objects. As a lower level than the "std::async()", I can choose when the task starts up, and which thread it runs on.

std::async(): 

Advantages:

As the simplest way to execute a task, it's very easy to obtain the return value from the task,  and if the task throws an exception, it's quite simple to catch that.

Also, I have the choice whether to run the task synchronously in the same thread as the caller, or asynchronously in a different thread.

As the higher level of abstraction than the std::thread,  the library can manage the thread automatically for me, and I don't need to use shared data to send results from 1 thread to another.

Disadvantages:

Lack of ability to "detach".

The task is "implicitly joined" if I execute it with the "async" launch options. That means if I have reached the end of an enclosing scope of caller, and called the destructor of the returned future, the destructor call will block until the task complete.

## Which situations are best suited to each of these options?

In general situation(just want to start a thread): use std::async()

If I want a container of thread objects, I can use std::packaged_task

If I need a detachable thread: use std::thread
