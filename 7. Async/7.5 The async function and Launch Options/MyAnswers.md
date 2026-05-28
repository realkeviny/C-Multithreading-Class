# The Async Function and Launch Options Exercises

## Exercise 1: Launch Options

### Write down a statement which uses std::async() to execute a task function func(), in which

### • The task executes in a separate thread

std::async(std::launch::async, func);

### • The task executes in the same thread

std::async(std::launch::deferred, func);

### Examine the effects of different launch policies in the following:

```cpp
int func()
{
return 42;
}
auto result = std::async(func);
std::cout << result.get() << '\n';
```

### • Add suitable print statements to show

### • When the task function is called

### • Which thread it is called in

### • Explain your results

About to call func() with async
Thread ID(Starter): 23912
Thread ID(func): 28244
42
About to call func() with deferred
Thread ID(Starter): 23912
Thread ID(func): 23912
42
About to call func() with none
Thread ID(Starter): 28244

Thread ID(func): 23912

42

With the async option, the func and the caller are running on different threads.

A new thread starts immediately-> func() executes in new thread(with a data race) -> main() continue to execute and call get() -> get() blocks until func()'s completion -> Use the result

With the deferred option, the func and the called are running on the same thread.

main() continue to execute and call get() -> The func() starts and run in the same thread as main() -> get() blocks until func()'s completion -> Use the result

With nothing, the implementation will decide the plan to run, apparently it chose to run the func on a dedicated thread.
