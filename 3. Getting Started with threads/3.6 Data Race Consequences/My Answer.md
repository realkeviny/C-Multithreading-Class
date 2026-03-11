### 001

**Code Sample:**

C++

```
const int x{5};

int func1() {
    return 2*x;
}

int func2() {
    return 3*x;
}
```

- **My Ans:** Yes. There are 2 threads are accessing the same memory location, which is x. x may be modified in any of these functions (Taking an integer by value is taking a copy of that integer), which will cause the other function calculating the result based on the modified value.
    
- **Correction:** **No.** `x` is a `const` variable; no thread can modify it. A data race requires at least one thread to perform a write operation. Unless the `const` is cast away (which would be UB), no conflict will occur.
    

---

### 002

**Code Sample:**

C++

```
int x{0}, y{0};

void func1() {
    if (x)
        y = 1;
}

void func2() {
    if (y)
        x = 1;
}
```

- **My Ans:** Yes. Still, assume I created 2 threads, each of them rules one of the functions. Potential Case: When the thread that executes func1 is about to see if the condition is satisfied, thread that executes func2 interleaves and changed x to 1. That means when switched back to thread 1, the condition will be satisfied and y will not be changed.
    
- **Correction:** **No.** Given the initial values `x = 0, y = 0`, the execution will never reach the modification of `x` or `y`. Since no write operation is reachable, a data race cannot occur.
    

---

### 003

**Code Sample:**

C++

```
int x{0}, y{0};

void func1() {
    x = 1;
    int r1 = y;
}

void func2() {
    y = 1;
    int r2 = x;
}
```

- **Ans:** **Yes.** There is a big possibility that a data race will occur. Presume 2 threads are executing these functions, if one of the thread is modifying `x` while the other one is using `x`.