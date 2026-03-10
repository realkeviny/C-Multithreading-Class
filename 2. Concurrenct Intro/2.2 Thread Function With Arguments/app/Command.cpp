import <thread>;
import <iostream>;
import <utility>;
import <string>;

int main(int argc, char const *argv[])
{
    std::thread thr([](int i1, int i2)
                    { std::cout << "The sum of " << i1 << " and " << i2 << " is " << i1 + i2 << '\n'; }, 4, 7);
    thr.join();
}
