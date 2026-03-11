import <iostream>;
import <thread>;
import <string_view>;
import <string>;

/**
    TODO:Write a task function which takes an std::string argument
        • The task function has a loop which displays the argument
        • The display of the argument is implemented one character at a time
*/
void printer(std::string_view str_view)
{
    for (auto c : str_view)
    {
        std::cout << c << " ";
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::string str{"Convex"};
    std::jthread thr1(printer, str);
    std::jthread thr2(printer, str);
    std::jthread thr3(printer, str);
    return 0;
}
