# Condition Variable with predicates Exercises

## Exercise 1: Lost Wakeup

- ### What is meant by the term "lost wakeup"?

When the notification is sent out by the condition variable in a thread using notify, there are no threads that call wait() will receive the notification. The notification will be lost, and the wait could never get a notification to return. The program will be blocked forever.

Will happen if a writer thread calls "notify()" before the reader calls "wait()"

Or: <font color="red">A lost wakeup occurs when a thread notifies a condition variable, but there are no threads which are waiting on the condition variable</font>

## Exercise 2: Spurious Wakeup

- ### What is meant by the term "spurious wakeup"?

The thread which has blocked by wait suddenly wakes up while there is no notification.

(<font color="red"> A condition variable wakes up a thread, without any threads notifying the condition variable.</font>)

## Exercise 3: Lost Wakeup Avoidance

- ### Suggest how to avoid lost wakeups
  
  Use wait() with a predicate.
  
  In 2 steps:
  
  Add a shared bool flag which is visible in all the task functions for threads which use it. <font color="red">It will indicate to the reader whether there are any pending notifications. When a thread calls notify(), it sets the bool.</font>
  
  In the "wait()" call, provide a callable object that checks the flag(<font color="red">Before a thread calls wait, checks the bool</font>).
  
  <font color="red">If the bool is true, there has been a notification and the thread can continue. If the bool is false, there has been no notifications and the thread will call wait.</font>

## Exercise 4: Spurious Wakeup Avoidance

- ### Suggest how to avoid spurious wakeups

        Same as Lost Wakeup Avoidance.

## Exercise 5: Multiple Threads

- Explain the results

For “Call notify_one() once", one of the threads will be woken up while the other threads remains sleeping(<font color="red">There is a possibility that if no further notifications are sent to the condition variable, the program will be blocked indefinitely.</font>)

For "Call notify_all() once", all the 3 threads will be woken up by the condition variable. Each reader's "wait()" will return, and each thread can continue on the rest of the statements with the mutex locked.

For “Call notify_one() three times": same as "notify_all()".

<font color="aqua">Note for myself: The choice of which thread to wake up, and the order in which to wake them up, is made by the scheduler.</font>
