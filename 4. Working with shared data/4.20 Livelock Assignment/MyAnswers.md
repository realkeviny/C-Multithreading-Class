# Questions

Hint: while loop runs <font color="red">when the condition is true</font>

```cpp
int x{0};
 
void func() {
    while (x == 0) {
        x = 1 - x;
    }
}
 
std::thread thr1{ func };
std::thread thr2{ func };
```

1. Are there any possible scenarios in which neither thread is able to exit the loop? If so, how could this happen?

    Yes.

    There is a possible scenario like this:   

    Thread A goes to the while's Test part, and while thread A is about to modify the value to 1, thread B interleaves, and passed the test.

    Thread B modifies the value to 1, waiting to test.

    Thread A modifies the value to 0, waiting to test.

    Thread B found that the value has been modified to 0, so it passed the test again.

    Thread A found that the value has been modified to 0, and it also passed the test again.

    Thread B modifies the value to 1, waiting to test.

    Thread A modifies the value to 0, waiting to test.

    x's status is always changing, so these threads will always stay in the loop, and could never come out.

2. If so, suggest a way to fix the problem.
   
   I can introduce a lock to lock the mutex for the while loop, so that the threads can be synchronized, and get a relatively expected result.
   
   Current thread ID: 22800, x: 1
   Current thread ID: 26644, x: 1


