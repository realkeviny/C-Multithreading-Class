import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;

using namespace std::literals;

// Recursive Mutex
/*
std::recursive_mutex rmutex;
std::mutex mutex;

int factorial_bdesign(int n)
{
    if (n <= 1)
    {
        std::cout << "Returning " << 1 << std::endl;
        return 1;
    }

    std::lock_guard<std::recursive_mutex> lck_guard(rmutex);
    // rmutex.lock();
    // mutex.lock();

    // Critical Section(Begin)
    int retval{n * factorial_bdesign(n - 1)};
    std::cout << "Returning " << retval << std::endl;
    // Critical Section(End)

    // rmutex.unlock();
    // mutex.unlock();

    return retval;
}
*/

// Timed Mutex
/*
std::timed_mutex tmutex;

void task1()
{
    std::cout << "Task1 is trying to lock the mutex\n";
    tmutex.lock();
    std::cout << "Task1 locked the mutex\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 unlocking the mutex\n";
    tmutex.unlock();
}
*/

// try_lock_for()
/*
void task2()
{
    std::this_thread::sleep_for(500ms);
    std::cout << "Task2 is trying to lock the mutex\n";

    // Try for 1 second to lock the mutex
    while (!tmutex.try_lock_for(1s))
    {
        // If returned false.
        std::cout << "Task2 couldn't lock the mutex" << std::endl;
        // Try again on the next iteration.
    }

    // Returned true, moving into critical section
    std::cout << "Task2 locked the mutex\n";
    // End of critical section
    tmutex.unlock();
}
*/

// try_lock_until()
/*
void task2()
{
    std::this_thread::sleep_for(500ms);
    std::cout << "Task2 is trying to lock the mutex\n";
    auto deadline{std::chrono::system_clock::now() + 900ms};

    // Try until deadline to lock the mutex
    while (!tmutex.try_lock_until(deadline))
    {
        // If returned false.
        // Update Deadline and try again.
        deadline = std::chrono::system_clock::now() + 900ms;
        std::cout << "Task2 couldn't lock the mutex" << std::endl;
        // Try again on the next iteration.
    }

    // Returned true, moving into critical section
    std::cout << "Task2 locked the mutex\n";
    // End of critical section
    tmutex.unlock();
}
*/

std::timed_mutex tmutex;
// Unique Lock and try_lock_for/until
void task1()
{
    std::cout << "Task1 is trying to lock the mutex\n";
    std::lock_guard<std::timed_mutex> lck_guard(tmutex);
    std::cout << "Task1 locked the mutex\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 unlocking the mutex\n";
}

void task2()
{
    std::this_thread::sleep_for(500ms);
    std::cout << "Task2 is trying to lock the mutex\n";

    std::unique_lock<std::timed_mutex> uniq_lck(tmutex, std::defer_lock);
    // Try for 1 second to lock the mutex
    while (!uniq_lck.try_lock_for(1s))
    {
        // If returned false.
        std::cout << "Task2 couldn't lock the mutex" << std::endl;
        // Try again on the next iteration.
    }

    // Returned true, moving into critical section
    std::cout << "Task2 locked the mutex\n";
    // End of critical section
}

int main(int argc, char const *argv[])
{
    std::jthread thr1(task1);
    std::jthread thr2(task2);

    return 0;
}
