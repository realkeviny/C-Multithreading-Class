# Exercise 1: Single Producer with Multiple Consumers

## What is meant by "Single Producer, Multiple Consumers"?

A situation that there are multiple consumer threads waiting for the same result, with one producer producing the result.

## Give an example where this could be useful

Assume there's a notice posted online, which is produced by one single company.

This notice is available for players around the world, and allows them to do various actions.

# Exercise 2: std :: future and Multiple Waiting Threads

## Why is it not safe to use std :: future when there are multiple waiting threads?

std::future is a class which designed specially for use with a single consumer thread. The object of this class assumes that it has exclusive read access to the shared state.

<font color="red">std::future is a move-only class.</font>

<font color="red">Sharing objects of the std::future class between threads will cause a data race.</font>

# Exercise 3: Obtaining an std :: shared_future object

## Give three ways to obtain a std :: shared_future object

1. Move an existing std::future object into the shared_future object.

2. Call share() member function of std::future to turn it into a std::shared_future object.

3. Call the get_future() on the promise, and convert the result to a std::shared_future object.
