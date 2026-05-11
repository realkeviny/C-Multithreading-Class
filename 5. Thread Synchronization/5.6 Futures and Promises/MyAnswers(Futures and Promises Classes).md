## Exercise 1: Transfer of Data using Future and Promise

## Briefly describe how the producer-consumer model can be implemented using std :: future and std :: promise

    The producer thread will take the promise object as the argument(Should be passed by reference, since the function needs to modify it). And the consumer thread will take the future object as the argument.

    The consumer task function will call get() on its future object. This function will block the consumer thread until the result becomes available.

    When the producer thread has done its work, call set_value() of the promise object to send the result, which means stores the result in the shared state.

    When the get() call in the consumer thread returns, that means the get() has read the  result from the shared state and is returning it.

# Exercise 2: std :: future

## What is the difference between the get() and wait() member functions of std :: future?

get(): Block the thread and wait <font color="red">until the promise object stores the result in the shared state.</font>

wait(): Block the thread, but don't return the value.

# Exercise 3: std :: promise Interface

## Which member function(s) does std :: promise use to access the shared state?

set_value(): Store a value in the share state.

set_exception(): Store an exception if an exception is thrown(/<font color="red"> forwards an exception</font>).

# Exercise 4: Producer-Consumer Model

## How would you create the std :: promise and std :: future objects, when writing a program that uses the Producer-Consumer model?

The promise object is created in the parent thread by calling its constructor.

Never create future object directly, just use get_future() to obtain the associated future object.

Instantiate them using the desired return value type.

## How are these objects associated with the appropriate threads?

<font color="red">The std::promise object is passed to the producer thread's task function by reference. As for the std::future object, it's passed to the consumer thread's task function by reference.
