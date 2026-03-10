import <thread>;
import <iostream>;

void print(std::string str)
{
    for (size_t i = 0; i < 5; ++i)      
    {
        std::cout << str[0] << str[1] << str[2] << std::endl;
    }
    
}

int main(int argc, char const *argv[])
{
    std::jthread thr1(print,"abc");
    std::jthread thr2(print,"def");
    std::jthread thr3(print,"xyz");

    return 0;
}
