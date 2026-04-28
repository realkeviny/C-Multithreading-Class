# Multiple Reader and Single Writer Questions

## Exercise 1: Multiple Reader, Single Writer

- ### What is meant by "Multiple Reader, Single Writer"?
  
  A situation where there is a shared data which is read by many threads, but only a few threads are modifying it.

- ### Give some examples of applications which use this pattern.
  
  Imagine applicants who are applying a project. For selected candidates, they can  receive a spreadsheet, which consists of the selected applicant ID, time for the interview, and the link to reach it. Applicants are constantly accessing this document, looking for the update of this spreadsheet. However, the creator will hardly update this document and put new information in.

- ### What issues are there with "Multiple Reader, Single Writer"?

        If I use mutex, the threads(including writer threads and reader threads), they are either all synchronized or none of them are synchronized.
        Moreover, if all threads are sychronized, they are just executing sequentially(even though reader threads are safe and don't need to be synchronized), which could eventually results of performance loss.

## Exercise 2: std::mutex Example

- ### How long do you expect it will take the program to run?

        3~4 seconds.

- ### Explain the results
  
  The program take 4 seconds(maybe more) to finish executing.
  
  According to the code:

```cpp
    std::vector<std::jthread> joinableThreads;
    for (size_t i = 0; i < 20; ++i)
    {
        joinableThreads.emplace_back(std::jthread(reader));
    }

    joinableThreads.emplace_back(std::jthread(writer));
    joinableThreads.emplace_back(std::jthread(writer));

    for (size_t i = 0; i < 20; ++i)
    {
        joinableThreads.emplace_back(std::jthread(reader));
    }
```

The threads will start and try to lock the mutex.

At first, the first one will lock the mutex, and execute its critical section.

No other thread can lock the mutex.

Sequential Execution: 40 (Threads) * 100ms(=0.1s) = 4s
