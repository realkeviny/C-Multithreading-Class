import singleton;
import <thread>;
import <vector>;
import <iostream>;

void task()
{
    Singleton &single = get_Singleton();
    std::cout << &single << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 10; ++i)
    {
        threads.push_back(std::thread(task));
    }

    for (auto &thr : threads)
    {
        thr.join();
    }

    return 0;
}
