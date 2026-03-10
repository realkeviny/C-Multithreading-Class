import <thread>;
import <iostream>;
import <chrono>;

void hello()
{
    using namespace std::literals;
    std::this_thread::sleep_for(2s);
    std::cout << "Hello, thread\n";
}

int main(int argc, char const *argv[])
{
    std::thread worker(hello);
    std::cout << "Worker thread's ID: " << worker.get_id() << std::endl;
    std::cout << "Main thread's ID: " << std::this_thread::get_id() << std::endl;

    worker.join();
    std::cout << "Worker thread's ID after join: " << worker.get_id() << std::endl;

    return 0;
}
