# Critical Section Exercises

## Explain what is meant by the term "critical section"

Critical section is a section of code which must only be executed by 1 thread/process at any time.

## Why is this important in multi-threaded programs?

Because the code section that is named critical section is mostly revolves around accessing shared resource, which will be done by numerous threads or processes. In addition, it will easily cause data race without any locking protocol or synchronization.


