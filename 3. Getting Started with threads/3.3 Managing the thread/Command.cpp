import <thread>;
import <iostream>;

class thread_guard
{
private:
    std::thread thr;

public:
    explicit thread_guard(std::thread &&thr) : thr(std::move(thr)) {};
    ~thread_guard()
    {
        if (thr.joinable())
        {
            thr.join();
        }
    }

    thread_guard(const thread_guard &) = delete;
    thread_guard &operator=(const thread_guard &) = delete;
};

void greet()
{
    std::cout << "Hello,World" << std::endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::thread tthr(greet);
        thread_guard guard{std::move(tthr)};

        throw std::exception();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
