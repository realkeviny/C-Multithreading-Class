# What purpose does sleeping achieve?
To make sure each thread could execute its function thoroughly, and the execution won't be interleaved by other threads.

# What is meant by the following, in the context of C++ threads?

## Interleaved execution
A thread starts to execute while the thread before it has been halted.

Check: <font color='red'>Threads execute in between each other. </font>

## Memory location
A scalar object that can be a variable of built-in types, a pointer, an element of containers, a member of class(variable, pointer, container element).

Check: <font color='red'>Compound objects, including containers in STL that behave like memory locations.</font>

## Data race
A special case of a race condition that the outcome will depend on when scheduler decides that thread should run, likely to occur when 2 or more threads are accessing the same memory location, with one of them is modifying this memory location.

Check: <font color='red'>Without synchronization.</font>
## Race condition
A phenomenon which describes that the result <font color='red'>program execution</font> is affected by timing changes<font color='red'>(/scheduled thread execution order)</font>.


