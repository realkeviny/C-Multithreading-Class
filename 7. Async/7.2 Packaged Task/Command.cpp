import <future>;
import <iostream>;
import <chrono>;
import <thread>;

using namespace std::literals;

int main(int argc, char *argv[])
{
    std::packaged_task<int(int, int)> ptask([](int a, int b) {
        std::this_thread::sleep_for(2s);
        return a + b;
    });

    std::future<int> ifut{ptask.get_future()};

    // In the same thread
    //  ptask(2, 9);

    // In a dedicated thread
    std::thread thr(std::move(ptask), 2, 9);

    std::cout << "Waiting for result\n";

    std::cout << "2 + 9 = " << ifut.get() << '\n';

    thr.join();
}