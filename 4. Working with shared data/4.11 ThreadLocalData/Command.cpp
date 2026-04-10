import <thread>;
import <iostream>;
import <random>;

std::mt19937 mt; // Random Number Engine

// Task Function
void func()
{
    std::uniform_real_distribution<double> dist(0, 1);

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << dist(mt) << ", ";
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "\nThread 1's random values: \n";
    std::thread thr1(func);
    thr1.join();

    std::cout << "\nThread 2's random values: \n";
    std::thread thr2(func);
    thr2.join();

    std::cout << '\n';
    return 0;
}
