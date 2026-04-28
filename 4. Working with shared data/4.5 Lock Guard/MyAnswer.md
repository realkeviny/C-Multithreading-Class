# Lock Guard Exercises

## Exercise 1: Exception Thrown in Critical Section

- ### Explain what happens if an exception is thrown in a critical section.
  
  The flow will immediately jump to the catch block which could handle the exception. However, since the critical section is usually come with mutex, if the unlock call is at the end of the critical section, that call will never be invoked,and the mutex may remain locked when I reach the catch block.
  
  <font color="red">All threads that are waiting to lock the mutex will be blocked, and any code who called join() on blocked threads will also be blocked. Eventually, the whole program will be blocked.</font>

- ### What approaches can programmers use to manage this situation?
  
  The best way is to use the lock_guard/<font color="red">Mutex wrapper classes, they use the RAII idom to manage the mutex. These take advantage of the fact that, when an exception is thrown, the destructors are called for every object in scope.</font> 
  
  The mutex will be unlocked when the flow goes out of the scope of the try block.
  
  A method discovered by myself: Add an extra call to unlock() explicitly in the catch block(But this is a verbose way, and most of the developers will never use the mutex class explicitly, so it's not recommended).

## Exercise 2: Drawbacks of std::mutex

- ### Are there other situations where these approaches are useful? If so, give some examples

Yes.

<font color="red">Thread function with multiple return paths ("return" statements)</font>
<font color="red"> Loop which locks a mutex and has "break" or "continue" statements.</font>

When using a function and that function has a critical section, I can also use the lock_guard for synchronization.

Local Scope in a function.

Or Complex branches.

## Exercise 3: std::lock_guard

- ### Do you notice anything unusual?(unscramble)

Result:  

abc
abc
abc
def
xyz
abc
def
xyz
abc
def
xyz
xyz
def
xyz
def

<font color="red">There is a noticeable delay between each output.</font>

That's because the mutex is still locked even if the flow has left the critical section and goes to the safe code(/<font color="red"> Until the end of the loop</font>). 

<font color="red">The sleep statement is executed while the mutex is still locked
Other threads cannot enter their critical section while this thread is sleeping</font>

- ### What happens when you run the program(Exception added)

Result:

abc
Here comes an exception~def

Here comes an exception~
xyz
Here comes an exception~
def
Here comes an exception~
xyz
Here comes an exception~
abc
Here comes an exception~
abc
Here comes an exception~xyz

def
Here comes an exception~
Here comes an exception~
xyz
Here comes an exception~abc

def
Here comes an exception~
Here comes an exception~
xyz
Here comes an exception~
def
Here comes an exception~abc

Here comes an exception~

All of the threads can work properly, and they can execute their own critical section.

In addition, all the exceptions are caught.

- ### Explain your results
  
  When the exception has been thrown, the object will also goes out of scope, and the destructor will be called automatically(For mutex wrapper class, the relevant mutex will be unlocked. For other objects, the memory will be released).
  
  Since the lock_guard's destructor has been called for unlocking the mutex, the next thread can get the mutex and lock it, then run the critical section.
  
  No thread will be blocked.

- ### Suggest one feature that could usefully be added to std :: lock_guard
  
  It must be unlock(), with that, I can choose when to unlock the mutex(<font color="red"> It would prevent unnecessary blocking of other threads when executing code after the critical region</font>)
