import <algorithm>;
import <string>;
import <iostream>;
import <cctype>;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <char>\n";
        return 1;
    }
    std::string str{};
    std::getline(std::cin, str);
    std::cout << "String Received: " << str << std::endl;

    auto ret{std::find_if(str.cbegin(), str.cend(),
                          [=](const char c) { return std::toupper(c) == std::toupper(argv[1][0]); })};

    if (ret != str.cend())
    {
        std::cout << "Found " << argv[1][0] << " at " << ret - str.cbegin() << std::endl;
    }
    else
    {
        std::cout << "Not Found!" << std::endl;
    }
}