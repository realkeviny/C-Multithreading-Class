import <iostream>;
import <utility>;

class Test
{
public:
    Test(const Test &) = delete;
    Test &operator=(const Test &) = delete;

    Test(Test &&) noexcept = default;
    Test &operator=(Test &&) noexcept = default;

    Test() = default;
};

int main(int argc, char const *argv[])
{
    Test test1, test2, test3;
    Test test4{test1};
    test2 = test1;
    Test test4{std::move(test1)};
    test3 = std::move(test2);
    return 0;
}
