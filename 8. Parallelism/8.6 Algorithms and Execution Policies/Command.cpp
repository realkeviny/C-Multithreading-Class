import <iostream>;
import <vector>;
import <algorithm>;
import <execution>;
import <ranges>;

namespace se = std::execution;
int main(int argc, char *argv[])
{
    std::vector<int> ivec{3, 1, 4, 1, 5, 9};
    try
    {
        // std::sort(ivec.begin(), ivec.end(), [](int a, int b) {
        //     throw std::out_of_range("Incoming Exception");
        //     return true;
        // });

        std::sort(se::seq, ivec.begin(), ivec.end(), [](int a, int b) {
            throw std::out_of_range("Incoming Exception");
            return true;
        });
    }
    catch (std::exception &ex)
    {
        std::cerr << "Caught Exception: " << ex.what() << std::endl;
    }

    // std::for_each(se::par, ivec.begin(), ivec.end(), [&count](int &x) { x = ++count; });

    for (auto &i : ivec)
    {
        std::cout << i << ',';
    }
    std::cout << std::endl;
}
