# Exercise 1: std :: future and std :: promise

## Briefly describe the std :: future and std :: promise classes

   <font color="red"> These classes are used to send data between threads.</font> When I create objects of these two classes, they will set up a shared state between them. This shared state can be used to transfer data from 1 thread to another.

## What are the advantages of using these classes?

1. No need to have any share data variables.

2. No explicit locking.

# Exercise 2: Producer-Consumer Model

## Briefly describe the producer-consumer model

We have a producer thread, associated with a promise object, which will generate a result.

We also have a consumer thread, associated with a future object, whichc will wait for the result.

The consumer thread will call a member function in the future class, which will block the thread until the result becomes available.

The producer thread will generate the result, and store that in the shared state, this mechanism will send the result off to the consumer.

Then, the consumer thread will wake up, and the member function will fetch the result from the shared state, and it will return.
