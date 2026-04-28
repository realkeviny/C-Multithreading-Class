import <iostream>;
import <thread>;
import <vector>;
import <string>;
import <mutex>;

// TODO Rewrite the "scrambled output" program using a mutex to protect the output operations.
// Verify that the output is not scrambled when there are ten concurrent threads running.

std::mutex mutex_for_printer;

void printer(std::string_view str_view)
{
    mutex_for_printer.lock();
    for (auto c : str_view)
    {
        std::cout << c;
    }
    std::cout << std::endl;
    mutex_for_printer.unlock();
}

void printer_one_line(std::string_view str_view)
{
    for (size_t i = 0; i < 10; ++i)
    {
        mutex_for_printer.lock();
        std::cout << str_view[0] << str_view[1] << str_view[2] << str_view[3] << str_view[4] << str_view[5] << std::endl;
        mutex_for_printer.unlock();
    }
}

int main(int argc, char const *argv[])
{
    std::string str{"Convex"};
    std::vector<std::jthread> threads;
    for (size_t i = 0; i < 10; ++i)
    {
        threads.emplace_back(std::jthread(printer, str));
    }

    for (size_t i = 0; i < 10; ++i)
    {
        threads.emplace_back(std::jthread(printer_one_line, str));
    }
    return 0;
}
