import <thread>;
import <iostream>;
import <mutex>;
import <string_view>;
import <chrono>;

using namespace std::literals;

std::mutex task_mutex;

// Lock & Unlock
//  void print(std::string_view str)
//  {
//      for (size_t i = 0; i < 5; ++i)
//      {
//          task_mutex.lock();
//          std::cout << str[0] << str[1] << str[2] << std::endl;
//          task_mutex.unlock();
//      }
//  }

// lock() VS try_lock()
void task1()
{
    std::cout << "Task1 is about to lock the mutex..." << std::endl;
    task_mutex.lock();
    std::cout << "Task1 locked the mutex successfully!" << std::endl;
    std::this_thread::sleep_for(500ms);
    std::cout << "Task1 is about to unlock the mutex..." << std::endl;
    task_mutex.unlock();
}

void task2()
{
    std::this_thread::sleep_for(100ms);
    std::cout << "Task2 is about to lock the mutex..." << std::endl;
    while (!task_mutex.try_lock())
    {
        std::cout << "Task2 can't lock the mutex!" << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "Task2 locked the mutex successfully!" << std::endl;
    task_mutex.unlock();
}

int main(int argc, char const *argv[])
{
    // std::jthread thr1(print, "abc");
    // std::jthread thr2(print, "def");
    // std::jthread thr3(print, "xyz");

    std::jthread thr1(task1);
    std::jthread thr2(task2);
    return 0;
}
