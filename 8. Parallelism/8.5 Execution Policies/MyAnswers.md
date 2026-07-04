# Exercise 1: Code Execution

## Briefly explain what is meant by the following type of execution

### • Sequential

A single instruction processes 1 data item(/operation).

<font color="red">An operation is performed in a single instruction</font>

### • Vectorized

A single instruction processes multiple data items(/operations). As long as there is a suitable data structure, with all the elements are contiguous, and hardware support, the processor must be able to deal with these instructions.

### • Parallel

Several instructions, each processes 1 data item(/operation), at the same time.

It requires a suitable algorithm, which can either divides the computation up into smaller pieces, or splitting the data up into smaller pieces.

### • Parallel + Vectorized

Several instructions, each processes several data items(operations), at the same time.

It requires a suitable choice of algorithm, a suitable data structure, and hardware support.

# Exercise 2: Execution Policies

## Compare the output from each program

*: To deal with computer with better performance, increased the amount of test data to 700,000 from 20,000.

For Sequential Execution Mode(seq): The output can reach 700,000 normally.

For Parallel Execution Mode(par):The output can reach 700,000 normally.

For unsequenced Execution Mode(unseq): The output can reach 700,000 normally.

For Parallel Unsequenced Execution Mode: Data corrupted.

![](C:\Users\Overd\AppData\Roaming\marktext\images\2026-06-27-01-18-04-image.png)

When count reaches 691,442, it suddenly jumps back to 690,619.

## Explain any unusual features

The "count" variable is shared between threads without any protection, so a data race could cause the result differs from 700,000

Operations performed on different threads may interleave, if there's an algorithm which performs modification, I will have a data race.
