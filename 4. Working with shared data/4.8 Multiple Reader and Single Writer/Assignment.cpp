import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <vector>;
import <string>;
using namespace std::literals;

std::string game_name{"MetalSlug"};
std::mutex mtx;

void writer()
{
    std::lock_guard<std::mutex> writer_guard(mtx);
    game_name += 'X';
}

void reader()
{
    std::lock_guard<std::mutex> reader_guard(mtx);
    std::this_thread::sleep_for(100ms);
}

int main(int argc, char const *argv[])
{
    std::vector<std::jthread> joinableThreads;
    for (size_t i = 0; i < 20; ++i)
    {
        joinableThreads.emplace_back(std::jthread(reader));
    }

    joinableThreads.emplace_back(std::jthread(writer));
    joinableThreads.emplace_back(std::jthread(writer));

    for (size_t i = 0; i < 20; ++i)
    {
        joinableThreads.emplace_back(std::jthread(reader));
    }

    return 0;
}
