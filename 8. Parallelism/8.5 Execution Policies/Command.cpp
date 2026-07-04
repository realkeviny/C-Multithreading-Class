import <iostream>;
import <vector>;
import <algorithm>;
import <execution>;
import <ranges>;

namespace se = std::execution;
int main(int argc, char *argv[])
{
    std::vector<int> ivec{3, 1, 4, 1, 5, 9};
    // std::vector<int> ivec(700'000);
    // int count{};
    // std::sort(se::seq, ivec.begin(), ivec.end(), std::greater<int>{});
    // std::sort(se::par, ivec.begin(), ivec.end(), std::greater<int>{});
    // std::sort(se::unseq, ivec.begin(), ivec.end(), std::greater<int>{});
    std::sort(se::par_unseq, ivec.begin(), ivec.end(), std::greater<int>{});

    // std::for_each(se::par, ivec.begin(), ivec.end(), [&count](int &x) { x = ++count; });

    for (auto &i : ivec)
    {
        std::cout << i << ',';
    }
    std::cout << std::endl;
}
