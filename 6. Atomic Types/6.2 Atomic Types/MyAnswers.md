# Exercise: Atomic

## Make the variable atomic

### Do you still get data corruption?

No

## Make the variable volatile

### Do you still get data corruption?

Yes

## Briefly explain your results

Normal: Data race. Threads are interleaving each other while incrementing that variable.

When making a variable "atomic", all the operations on that variable will be atomic. Other threads won't be able to interleave during that operation, and interfere with the operation on the variable.
Like in this program, all the operations, pre-fetch, increment, and publish the result could go uninterruptly. Just like a single operation which can't be interrupted.

About volatile: In C++, it has no effect on thread safety.


