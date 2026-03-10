import <random>;
import <iostream>;

std::mt19937 engine;

int main(int argc, char const *argv[])
{
    std::uniform_int_distribution<int> idis(0, 10);

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << idis(engine) << " ";
    }

    std::cout << std::endl;
    std::cout << "-----------------------------" << std::endl;

    std::uniform_real_distribution<double> rdis(0, 100);

    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << rdis(engine) << " ";
    }
    return 0;
}
