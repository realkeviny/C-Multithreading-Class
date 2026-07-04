# Exercise 1: std::transform()

# Briefly describe the std::transform() function

This function will iterate through the input container, and will pass each element as an argument to the callable object, then finally store the return value as an argument of the target container.

## Write a program to demonstrate its use



# Exercise 2: Binary overload of std::transform()

## Briefly describe the binary overload of std::transform()

This will invoke the function with an element from each of the 2 input containers as argument, and use the result to populate the output vector.

Requires an additional source container.

## Write a program to demonstrate its use



# Exercise 3: Transform and Reduce Pattern

## Briefly describe the "transform and reduce" pattern

1. Divide the data into subsets.

2. Start a thread for each subset to process data.

3. Arrange things so that each thread calls "std::transform()", which will process the data in that subset by doing something, and produce a result for that part of data("Map").

4. Call "std::reduce()" to combine each of these partial results from the transform threads into the final answer("Reduce").



# Exercise 4: std::inner_product

## Briefly describe the std::inner_product() function

Multiply the corresponding elements of 2 containers, and add up the results to an initial value.



# Exercise 5: std::transform_reduce()

## Briefly describe the std::transform_reduce function

Reimplemented std::inner_product() to support execution policies.

## Why is transform_reduce particularly useful in parallel programming?

<font color="red">It can be used to implement the "map and reduce" pattern.</font>

## What are the advantages of combining std::transform() and std::reduce() into a single function?

The "std::transform()" threads don't need to serialize their results, and have it read again by the reduce call.

It allows the output from the transform operations to be piped directly into the reduce operation. So that the std::reduce() can start working, as soon as there is some output, without having to wait for every "std::transform()" thread to finish.

If the reduce stage needs to start some threads, it can reuse the ones which were used by the transform stages.


