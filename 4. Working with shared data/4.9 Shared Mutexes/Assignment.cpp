import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <vector>;
import <string>;
import <shared_mutex>;
using namespace std::literals;

std::string game_name{"MetalSlug"};
std::shared_mutex smtx;

void writer()
{
    std::unique_lock<std::shared_mutex> writer_guard(smtx);
    game_name += 'X';
}

void reader()
{
    std::shared_lock<std::shared_mutex> reader_guard(smtx);
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
