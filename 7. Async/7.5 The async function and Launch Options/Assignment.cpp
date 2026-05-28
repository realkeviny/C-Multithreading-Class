import <iostream>;
import <future>;
import <string_view>;
import <chrono>;

using namespace std::literals;

int func()
{
    std::cout << "Thread ID(func): " << std::this_thread::get_id() << std::endl;
    return 42;
}

int main(int argc, char *argv[])
{
    std::cout << "Run func with async option" << std::endl;
    auto result{std::async(func)};
    std::cout << "Thread ID(main): " << std::this_thread::get_id() << std::endl;
    std::cout << "About to call .get()" << std::endl;
    std::cout << result.get() << '\n';
}