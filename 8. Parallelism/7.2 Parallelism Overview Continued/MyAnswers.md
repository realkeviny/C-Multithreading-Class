# Task and Data Parallelism

## Briefly explain the difference between task parallelism and data parallelism

Task parallelism divides the large computational task into smaller subtasks and  distributes over a number of cores. Usually implemented based on "Fork and Join" paradigm. Each of these subtasks will be run on a different thread. <font color="red">The threads usually perform different work</font>

Data parallelism divides the large data set into several smaller subsets and distributes over various cores. One thread for each subset. Usually implemented with "Vectorization" diagram. <font color="red">The threads usually perform the same work</font>


