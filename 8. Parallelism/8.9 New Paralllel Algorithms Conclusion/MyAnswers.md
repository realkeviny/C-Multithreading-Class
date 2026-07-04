# Exercise 1: Disadvantages of Execution Policies

## Give some disadvantages of execution policies

1. I can ask for an execution policy, but the compiler isn't required to give me one(Some compilers may won't compile; Others may will give me the old non-policy version; Even if the compiler does implement execution policies, it may not have implemented them for all the algorithms in the library).

2. Execution policies may cause extra overhead(If the algorithm starts up new threads, then these are going to use system resources, and it will take time to start up those threads and shut them down; The algorithm has to manage these threads.)

# Exercise 2: When to Use anExecution Policy?

## Suggest some situations where it would not be desirable to use an execution policy

1. My code has to be portable to other compilers.

2. The task is essentially sequential.

3. Operation order is important.

4. The algortithm call throws exceptions.

5. If immediate termination is unacceptable.

6. The cost of preventing data races is more than using non-policy version.

# Exercise 3: Which Execution Policy to use?

## Describe when you would use each of the execution policies, and explain why

Sequenced Execution--------Useful while debugging, since it allows out-of-order execution, and it will terminate the entire program if there are any exceptions.

<font color="red">guaranteed to only use one thread</font>

Parallel Execution----------If I want concurrent execution, but vectorization is not safe. It allows the code to modify shared state, but doesn't allow the data races' occurences.

Unsequenced Execution-----------If I have a C++ 20 compiler, I can use that in a single threaded program for better performance.But, the code is not allowed to modify shared state.

Parallel Unsequenced Execution-----------It has the most potential for making my program run faster, since it gives me the benefit of concurrency and vectorization.

However, it has the strictest requirements: No data races should occur; The code shouldn't modify shared state.


