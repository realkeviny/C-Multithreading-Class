import <mutex>;
import <string>;
import <iostream>;
import <thread>;
import <chrono>;

using namespace std::literals;

/** TODO
 * Rewrite the try_lock program from "Mutex Introduction" to use
 * try_lock_for() with std::timed_mutex
 * try_lock_until() with std::timed_mutex
 * try_lock_for() with std::unique_lock
 * try_lock_until() with std::unique_lock
 */

// try_lock_for() with std::timed_mutex
/*
std::timed_mutex tmutex;
void task1()
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    tmutex.lock();
    std::cout << "Task1 locked the mutex successfully!" << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
    tmutex.unlock();
}

void task2()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    while (!tmutex.try_lock_for(200ms))
    {
        std::cout << "Task2 can't lock the mutex!" << std::endl;
    }
    std::cout << "Task2 locked the mutex successfully!" << std::endl;
    tmutex.unlock();
}
*/

// try_lock_until() with std::timed_mutex
/*
std::timed_mutex tmutex;
void task1()
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    tmutex.lock();
    std::cout << "Task1 locked the mutex successfully!" << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
    tmutex.unlock();
}

void task2()
{
    // std::this_thread::sleep_for(100ms);
    auto deadline{std::chrono::system_clock::now() + 200ms};
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    while (!tmutex.try_lock_until(deadline))
    {
        deadline = std::chrono::system_clock::now() + 200ms;
        std::cout << "Task2 can't lock the mutex!" << std::endl;
    }
    std::cout << "Task2 locked the mutex successfully!" << std::endl;
    tmutex.unlock();
}
*/

// try_lock_for() with std::unique_lock
/*
std::timed_mutex tmutex;
void task1()
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    std::unique_lock<std::timed_mutex> uniq_tlock(tmutex);
    std::cout << "Task1 locked the mutex successfully!" << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
}

void task2()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    std::unique_lock<std::timed_mutex> uniq_tlock(tmutex, std::defer_lock);
    while (!uniq_tlock.try_lock_for(200ms))
    {
        std::cout << "Task2 can't lock the mutex!" << std::endl;
    }
    std::cout << "Task2 locked the mutex successfully!" << std::endl;

    std::cout << "Task2 is about to unlock the mutex..." << std::endl;
}
*/

// try_lock_until() with std::unique_lock
std::timed_mutex tmutex;
void task1()
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    std::unique_lock<std::timed_mutex> uniq_tlock(tmutex);
    std::cout << "Task1 locked the mutex successfully!" << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
}

void task2()
{
    // std::this_thread::sleep_for(100ms);
    auto deadline{std::chrono::system_clock::now() + 200ms};
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    std::unique_lock<std::timed_mutex> uniq_tlock(tmutex, std::defer_lock);
    while (!uniq_tlock.try_lock_until(deadline))
    {
        deadline = std::chrono::system_clock::now() + 200ms;
        std::cout << "Task2 can't lock the mutex!" << std::endl;
    }
    std::cout << "Task2 locked the mutex successfully!" << std::endl;

    std::cout << "Task2 is about to unlock the mutex..." << std::endl;
}

int main(int argc, char const *argv[])
{
    std::jthread thr1(task1);
    std::jthread thr2(task2);
    return 0;
}
