import <iostream>;
import <vector>;
import <string>;

void func(std::vector<std::string>&& arg)
{
    std::cout << "Rvalue Ref" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> svec(1000000);

    std::cout << "Before: " << svec.size() << std::endl;
    func(std::move(svec));
    std::cout << "Then: "  << svec.size() << std::endl;

    return 0;
}
