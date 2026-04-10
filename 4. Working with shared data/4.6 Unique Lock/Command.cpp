import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <string_view>;

using namespace std::literals;

std::mutex mutex_for_task;

// Function with lock_guard
void taskFuncV3(std::string_view str)
{
    for (size_t i = 0; i < 5; ++i)
    {
        try
        {
            std::unique_lock<std::mutex> uniq_lck(mutex_for_task);

            std::cout << str[0] << str[1] << str[2] << std::endl;

            // uniq_lck.unlock();

            std::this_thread::sleep_for(50ms);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int main(int argc, char const *argv[])
{

    std::jthread thr1(taskFuncV3, "aac");
    std::jthread thr2(taskFuncV3, "rxe");
    std::jthread thr3(taskFuncV3, "ptl");
    return 0;
}
