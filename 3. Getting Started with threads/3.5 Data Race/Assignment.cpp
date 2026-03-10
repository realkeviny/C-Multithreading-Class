import <iostream>;
import <thread>;

int number{1};

void increment(int n, int times)
{
    for (size_t i = 0; i < times; ++i)
    {
        std::cout << number++ << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    {
        std::jthread counter1(increment, number, 100'000);
        std::jthread counter2(increment, number, 100'000);
    }
    std::cout << "Final Value: " << number << std::endl;
    return 0;
}
