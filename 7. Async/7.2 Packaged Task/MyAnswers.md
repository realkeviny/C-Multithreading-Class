# Packaged Task Exercises

## Exercise 1: std::packaged_task

### Briefly describe the std::packaged_task class

This is a class which encapsulates everything I need to execute a task. It has a callable object member which stores all the code for the task, and a promise member object, that is used for storing the result of the task.

It provides a higher level of abstraction than std::thread.

<font color="red">A std::packaged_task instance is itself a callable object</font>

The constructor of this class will take the name of the callable object, and the type template parameter will take the signature of callable, the callable object I pass must has the same signature as I stated in template parameter.

The associated future object of the promise member can be obtained by "get_future()", then I can call "get()" to get the result.

I can pass a packaged_task instance to a thread object by move, along with the arguments of the callable object. So that the task will run asynchronously in a separate thread.

Or I can simply call the function call operator, so that the task runs synchronously, in the same thread which invokes it.

## Exercise 2: Thread Container

Imagine you want to create a container whose elements are runnable threads
Which class would you use for the elements?

std::thread(The threads will start up as soon as I created the std::thread object) / std::packaged_task(I can choose when to start the thread in the thread object).


