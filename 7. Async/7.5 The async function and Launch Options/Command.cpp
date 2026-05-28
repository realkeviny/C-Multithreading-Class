import <future>;
import <iostream>;
import <chrono>;
import <thread>;
import <string>;
import <string_view>;

using namespace std::literals;

int task()
{
    std::cout << "Executing task() in thread with ID: ";
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(5s);
    std::cout << "Returning from task()\n";
    return 42;
}

void func(std::string_view option = "default")
{
    std::future<int> result;

    if (option == "async")
    {
        result = std::async(std::launch::async, task);
    }
    else if (option == "deferred")
    {
        result = std::async(std::launch::deferred, task);
    }
    else
    {
        result = std::async(task);
    }

    std::cout << "Calling async with option \"" << option << "\"\n";
    std::this_thread::sleep_for(2s);
    std::cout << "Calling get()\n";
    std::cout << "Task result: " << result.get() << '\n';
}

int main(int argc, char *argv[])
{
    std::cout << "In main thread with ID: " << std::this_thread::get_id() << std::endl;

    func("async");
    func("deferred");
    func("default");
}
