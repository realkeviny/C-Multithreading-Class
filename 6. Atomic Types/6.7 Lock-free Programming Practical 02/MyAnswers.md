# Exercise: Lock-free Programming Practical Continued

## Why does the constructor create an element which is not used for anything?

That element is a "dummy" element, which is simply used to ensure that the head and the tail iterator aren't pointing to the same element/working on adjacent elements.

## Explain why the data race occurs

The head and the tail iterator are accessed from different threads, and there is modification ocurring. Even though there is just one thread which is modifying, one thread which is reading.

There is no thread ordering, no atomic variables.

## Can the race condition be avoided by using atomic variables?

No, the iterator type variables' operations are not single-instruction operations, additionally, they are not of type that are trivailly copyable.
