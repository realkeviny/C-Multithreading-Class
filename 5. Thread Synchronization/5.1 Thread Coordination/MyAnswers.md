# Thread Coordination Questions

## Exercise 1: Hot Loop

### What is meant by a "hot loop"?

A loop which may run flat for many times, leads to a 100% occupied processor core.

### Why are hot loops considered bad?

It will fully occupy the processor core, and blocks other threads from using this processor core to modify the flag/do things to meet the ending condition because other threads can't lock the mutex, eventually cause a infinite loop..

## Exercise 2: Hot Loop Avoidance

### Suggest a way to avoid a "hot loop" in this code

```cpp
bool upgrade_process = false;

std::lock_guard data_lck(data_mutex);
while (!update_progress) {}
```

Unlock the mutex inside the loop, and then lock it again(<font color="red">/after checking the bool</font>)

```cpp
bool upgrade_process = false;

std::unique_lock uniq_data_lck(data_mutex);
while (!update_progress) 
{
    uniq_data_lck.unlock();
    std::this_thread::sleep_for(10ms);
    uniq_data_lck.lock();
}
```

### Is your proposed solution thread-safe?

Yes

<font color="red">The boolean is only accessed when the mutex is locked. In addition, When the thread leaves the loop, the mutex is still locked.</font>

### What advantages does your solution have?

The sleep with the mutex unlocked allows other threads to lock the mutex, and update the "update_progress" flag. So that the loop can always exit properly.

## Exercise 3: Implementation with Mutex

### Would you describe the example code in the video as elegant?

As for me, no.

Numerous explicit locking.

I need to care about the mutexes every moment, and I also need to control the duration of sleep, which is annoying and tiring.

If the duration is set too long, The thread will wait for longer than it should do, if too short , the hot loop will come back again.
