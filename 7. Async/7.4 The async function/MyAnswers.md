# The async Function Exercises

## Exercise 1: std::async()

### Briefly describe the std::async() function

This function provides a higher level abstraction than the others.

I can start a task which will run in the background/run the task synchronously on the same thread, as I did with the "packaged_task".

The syntax is similar to the constrcutor for the "std::thread" class, the task function's name as the first argument, with the arguments to the task function follows.

## Exercise 2: Returning a value

### What does std::async() return?

A future object, which consists of the result of the task.

## Exercise 3: Exceptions

### What happens if the task function throws an exception?

The exception will be stored in the future object. When I call "get()", the future will rethrow the exception.
