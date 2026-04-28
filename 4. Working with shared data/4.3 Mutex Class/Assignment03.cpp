/** TODO
 * Write a program which runs two task functions in separate threads
 * The first task function locks a mutex, sleeps for 500ms and releases
the lock
 * The second task function sleeps for 100ms, then calls try_lock() to
lock the mutex. If unsuccessful, it sleeps again for 100ms and calls
try_lock() again. If successful, it unlocks the mutex
 * Add suitable print statements and run the program
*/

import <mutex>;
import <string>;
import <iostream>;
import <thread>;
import <chrono>;

using namespace std::literals;

std::mutex mtx;

void task1(std::string_view str_view)
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    mtx.lock();
    std::cout << "Task1 locked the mutex..." << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout << str_view << std::endl;
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
    mtx.unlock();
}

void task2(std::string_view str_view)
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    while(!mtx.try_lock())
    {
        std::cout << "Task2 is waiting to Lock the mutex..." << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << str_view << std::endl;
    std::cout << "Task2 is about to unlock the mutex..." << std::endl;
    mtx.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread t1(task1, "Task 1: Locked the mutex!"sv);
    std::thread t2(task2, "Task 2: Finally got the lock!"sv);

    t1.join();
    t2.join();

    std::cout << "All tasks finished." << std::endl;

    return 0;
}