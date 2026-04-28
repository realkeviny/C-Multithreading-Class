// Use a mutex to avoid scrambled output
import <iostream>;
import <mutex>;
import <thread>;
import <string>;
import <chrono>;

using namespace std::literals;

// TODO: Rewrite the program from the previous lecture to use std::unique_lock

/*
// Global mutex object
std::mutex task_mutex;


void task(std::string_view str)
{
    for (int i = 0; i < 5; ++i)
    {
        std::unique_lock<std::mutex> uniq_lock(task_mutex);

        // Start of critical section
        std::cout << str[0] << str[1] << str[2] << std::endl;
        // End of critical section

        uniq_lock.unlock();

        std::this_thread::sleep_for(50ms);
    }
}
*/

// Global mutex object
std::mutex task_mutex;

void task(std::string_view str)
{
    for (int i = 0; i < 5; ++i)
    {
        std::unique_lock<std::mutex> uniq_lock(task_mutex);
        try
        {
            // Start of critical section
            std::cout << str[0] << str[1] << str[2] << std::endl;
            // throw std::exception();
            // End of critical section

            uniq_lock.unlock();

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
