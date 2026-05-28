import <future>;
import <iostream>;
import <thread>;
import <string>;

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage HomeworkExecutable " << "<arg1> <arg2>" << std::endl;
        return 1;
    }
    std::packaged_task<int(int, int)> ptask(add);

    std::future<int> ifut{ptask.get_future()};

    std::jthread executing_thread(std::move(ptask), std::stoi(argv[1]), std::stoi(argv[2]));

    std::cout << "Result: " << ifut.get() << std::endl;
}