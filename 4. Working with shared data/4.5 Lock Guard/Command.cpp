import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <vector>;
import <string_view>;

using namespace std::literals;

std::mutex mutex_for_task;

// void taskFunc(std::string_view str)
// {
//     for (size_t i = 0; i < 5; ++i)
//     {
//         try
//         {
//             mutex_for_task.lock();

//             std::cout << str[0] << str[1] << str[2] << std::endl;

//             throw std::exception("Here I come!Boom!");

//             mutex_for_task.unlock();
//             std::this_thread::sleep_for(50ms);
//         }
//         catch (const std::exception &e)
//         {
//             std::cerr << e.what() << '\n';
//         }
//     }
// }

// Function with lock_guard
void taskFuncV2(std::string_view str)
{
    for (size_t i = 0; i < 5; ++i)
    {
        try
        {
            std::lock_guard<std::mutex> lck_guard(mutex_for_task);

            std::cout << str[0] << str[1] << str[2] << std::endl;

            // throw std::exception();

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

    std::jthread thr1(taskFuncV2, "aac");
    std::jthread thr2(taskFuncV2, "rxe");
    std::jthread thr3(taskFuncV2, "ptl");
    return 0;
}
