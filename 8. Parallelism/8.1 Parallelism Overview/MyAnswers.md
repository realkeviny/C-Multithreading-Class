# Exercise 1: Concurrency and Parallelism

## Briefly explain the difference between concurrency and parallelism

Concurrency: <font color="red">when threads perform different tasks</font>

Usually describes "conceptually distinct" tasks. 
Each task has separate concerns<font color="red">(to keep conceptually tasks distinct and improve responsiveness)</font>

A concurrent program can run on a single core;It's not necessary to have multiple cores.

The tasks will often interact with each other, and can often overlap in time, they don't all have to start/fininsh at the same time. I can have tasks which start up other tasks.

Concurrency is a feature of the program structure, something that I design into the program, the way I choose to write the program.

---

Parallelism: <font color="red">when threads perform the same task</font>

Describe tasks that are "identical".

They are all doing the same thing, and they all run at the same time. I want to run these on multiple cores to get better scalability

These tasks are all completely independent of each other, there's no interaction between threads, and no dependency on each other.

Parallelism is a feature of the algorithm being run. It's used since it's the most efficient 

way to implement that algorithm.

<font color="red">mainly used for computationally intensive work, which can be split into units, and these units can be processed independently of each other</font>

# Exercise 2: Explicit and Implicit Parallelism

## Briefly explain the difference between explicit and implicit parallelism

Explicit parallelism: 

The programmer specifies how the work will be done, and the programmer has to actually write code to make the program parallel(<font color="red">the programmer has to choose how many threads to use and start them</font>)

It involves more work for the programmer, but can produce better performance. However, it's not scalable.

Usuallt used when writing code for specific hardware, or I have a problem which can be naturally divided up into a fixed number of tasks.

Implicit parallelism:

Leave the decision up to the implementation. It has to work out the most efficient way to solve the problem I give(<font color="red">the system will automatically start the optimal number of threads</font>).

It can make the best use of available resources.
