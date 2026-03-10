import <thread>;
import <iostream>;
import <chrono>;

void greet(int num)
{
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << "Hello from thread " << num << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "Starting 3 threads " << std::endl;

    // C++ 20
    std::jthread thr1(greet, 1);
    std::jthread thr2(greet, 2);
    std::jthread thr3(greet, 3);
}
