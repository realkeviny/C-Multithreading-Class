import <vector>;

int main(int argc, char const *argv[])
{
    std::vector<int> ivec{4, 2, 3, 5, 1};
    for (auto value : ivec)
    {
        std::cout << value << " ";
    }

    for (auto &value : ivec)
    {
        value += 2;
    }

    std::cout << std::endl;

    for (auto value : ivec)
    {
        std::cout << value << " ";
    }
    return 0;
}
