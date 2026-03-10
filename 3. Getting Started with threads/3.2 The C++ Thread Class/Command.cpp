import <thread>;
import <iostream>;
import <chrono>;

void hello()
{
    throw std::exception();
    std::cout << "Hello, Thread" << std::endl;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::thread thr(hello); 
        thr.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    std::cout << "Done!" << std::endl;
    return 0;
}
