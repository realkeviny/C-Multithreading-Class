import <thread>;
import <iostream>;

void hello()
{
    std::cout << "Hello, thread\n";
}

int main(int argc, char const *argv[])
{
    std::thread worker(hello);
    std::cout << "Worker thread's ID: " << worker.get_id() << std::endl;
    std::cout << "Main thread's ID: " << std::this_thread::get_id() << std::endl;

    worker.join();
    return 0;
}
