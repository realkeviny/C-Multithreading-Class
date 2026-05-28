// TODO: Write a simple "Hello, World!" type program which uses std::async()
import <iostream>;
import <future>;
import <string>;

/*
void greet()
{
    std::cout << "Hello,World" << std::endl;
}

int main(int argc, char *argv[])
{
    std::async(greet);
}
*/

// TODO: Write a program which uses std::async() to start a task and displays the returned value
/*
int subtractor(int a, int b)
{
    return a - b;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: HomeworkExecutable " << " arg1 arg2" << std::endl;
        return 1;
    }
    auto resulted_future{std::async(subtractor, std::stoi(argv[1]), std::stoi(argv[2]))};

    int value{resulted_future.get()};

    std::cout << "Result: " << value << std::endl;
}
*/

// TODO: Modify your program so that the task function throws an exception
int thrower()
{
    int t = 33;
    if (true)
        throw std::runtime_error("Here I come!");
    return t;
}

int main(int argc, char *argv[])
{
    auto result{std::async(thrower)};
    try
    {
        int ret{result.get()};
        std::cout << "The answer is " << ret << '\n';
    }
    catch (std::exception &ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}
