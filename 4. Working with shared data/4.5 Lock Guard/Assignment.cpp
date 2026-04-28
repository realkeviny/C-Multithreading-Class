// Use a mutex to avoid scrambled output
import <iostream>;
import <mutex>;
import <thread>;
import <string>;
import <chrono>;

using namespace std::literals;

/* TODO: Rewrite the unscramble program
        Instead of locking and unlocking a mutex directly,use std::lock_guard
        Add a sleep statement at the end of the loop
*/

/*
// Global mutex object
std::mutex task_mutex;

void task(std::string_view str)
{
    for (int i = 0; i < 5; ++i)
    {
        std::lock_guard lck_guard(task_mutex);

        // Start of critical section
        std::cout << str[0] << str[1] << str[2] << std::endl;
        // End of critical section

        std::this_thread::sleep_for(2s);
    }
}
*/

/* TODO: Throw an exception in the critical section
         Add a try-catch block to handle the exception
*/

// Global mutex object
std::mutex task_mutex;

void task(std::string_view str)
{
    for (int i = 0; i < 5; ++i)
    {

        std::lock_guard lck_guard(task_mutex);
        try
        {
            // Start of critical section
            std::cout << str[0] << str[1] << str[2] << std::endl;
            throw std::exception();
            // End of critical section

            std::this_thread::sleep_for(50ms);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int main()
{
    std::thread thr1(task, "abc");
    std::thread thr2(task, "def");
    std::thread thr3(task, "xyz");

    thr1.join();
    thr2.join();
    thr3.join();
}
