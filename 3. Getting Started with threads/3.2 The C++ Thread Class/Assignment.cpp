import <thread>;
import <iostream>;
import <exception>;

void greeting()
{
    // try
    // {
    std::cout << "Hello, World" << std::endl;
    //     throw std::runtime_error("Here comes an exception!");
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
}

std::jthread greetth()
{
    std::jthread thr(greeting);
    return thr;
}

void greetp(std::thread thr)
{
    std::cout << "Received thread's ID: " << thr.get_id() << std::endl;
    thr.join();
}

int main(int argc, char const *argv[])
{

    // 001
    std::thread t1(greeting);
    greetp(std::move(t1));
    // 002
    //  std::jthread recThread{greetth()};
    //  std::cout << "Thread ID: " << recThread.get_id() << std::endl;

    return 0;
}
