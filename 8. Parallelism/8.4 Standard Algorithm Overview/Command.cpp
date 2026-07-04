import <iostream>;
import <numeric>;
import <algorithm>;
import <cctype>;

int main(int argc, char *argv[])
{
    std::string str{"HellO, World"};
    std::cout << "String to search: " << str << std::endl;

    // Search for the first occurrence of 'o'
    std::cout << "Searching for the first occurrence of \'o\'" << std::endl;
    auto ret{std::find_if(str.cbegin(), str.cend(), [](const char c) { return ::toupper(c) == 'O'; })};

    // Found?
    if (ret != str.cend())
    {
        // Access Result
        std::cout << "Found a mathcing element at index : " << ret - str.cbegin() << std::endl;

        std::cout << "Now in the string: ";
        for (auto it = ret; it != str.cend(); ++it)
        {
            std::cout << *it;
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "Not Found!" << std::endl;
    }
}
