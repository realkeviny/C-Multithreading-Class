import <future>;
import <iostream>;
import <chrono>;
import <thread>;
import <string>;
import <string_view>;

using namespace std::literals;

void task()
{
    std::this_thread::sleep_for(5s);
    std::cout << "Result: " << 42 << std::endl;
}

void func()
{
    std::cout << "Calling async \n";
    auto result = std::async(std::launch::async, task);
}

int main(int argc, char *argv[])
{
    func();
    std::cout << "Task Started\n";
}
