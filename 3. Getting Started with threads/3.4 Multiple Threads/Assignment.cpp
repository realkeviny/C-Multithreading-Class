import <iostream>;
import <thread>;
import <chrono>;

void marker(int n, int interval)
{
    std::this_thread::sleep_for(std::chrono::seconds(interval));
    std::cout << "Thread " << n << " is calling this function..." << std::endl;
}

int main(int argc, char const *argv[])
{
    int counter{1};
    std::thread thr1(marker, counter, 1);
    std::thread thr2(marker, ++counter, 2);
    std::thread thr3(marker, ++counter, 4);

    thr1.join();
    thr2.join();
    thr3.join();
    return 0;
}
