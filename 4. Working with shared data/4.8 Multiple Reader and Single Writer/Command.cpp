import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <vector>;

std::mutex mutex;

int x{};

void write()
{
    std::lock_guard<std::mutex> lck_guard(mutex);

    // Entering Critical Section
    ++x;
    // Exiting Critical Section
}

void read()
{
    std::lock_guard<std::mutex> lck_guard(mutex);

    // Entering Critical Section
    using namespace std::literals;
    std::this_thread::sleep_for(100ms);
    // Exiting Critical Section
}

int main(int argc, char const *argv[])
{
    // Creating multiple threads
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(read));
    }
    threads.push_back(std::thread(write));
    threads.push_back(std::thread(write));

    for (size_t i = 0; i < 20; ++i)
    {
        threads.push_back(std::thread(read));
    }

    for (auto &thr : threads)
    {
        thr.join();
    }
    return 0;
}
