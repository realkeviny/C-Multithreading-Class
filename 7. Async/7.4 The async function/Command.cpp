import <future>;
import <iostream>;
import <chrono>;

// Simple Use
/*
void hello()
{
    std::cout << "Hello, Async!" << std::endl;
}

int main(int argc, char *argv[])
{
    std::async(hello);
}
*/

// Returns something
/*
unsigned long long fibonacci(unsigned long long n)
{
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[])
{
    std::cout << "Calculating fibonacci(30)\n";

    auto result{std::async(fibonacci, 30)};

    bool finished{};

    using namespace std::literals;
    while (result.wait_for(1s) != std::future_status::ready)
    {
        std::cout << "Waiting for the result... \n";
    }

    std::cout << result.get() << std::endl;
}
*/

// With Exceptions
int produce()
{
    int x{27};

    using namespace std::literals;
    std::this_thread::sleep_for(2s);

    if (false)
    {
        throw std::out_of_range("Incoming Exception");
    }

    std::cout << "Produce returning " << x << std::endl;
    return x;
}

int main(int argc, char *argv[])
{
    auto result{std::async(produce)};

    std::cout << "Future calling get()..." << std::endl;
    try
    {
        int x{result.get()};
        std::cout << "Future returns from calling get()..." << std::endl;
        std::cout << "The answer is " << x << '\n';
    }
    catch (std::exception &ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}
