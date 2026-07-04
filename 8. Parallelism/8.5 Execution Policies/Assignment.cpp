import <iostream>;
import <vector>;
import <algorithm>;
import <execution>;
import <ranges>;

int main(int argc, char *argv[])
{
    std::vector<int> vec(800'000);
    int count{};

    namespace se = std::execution;
    // std::for_each(se::seq, vec.begin(), vec.end(), [&count](int &x) { x = ++count; });
    std::for_each(se::par, vec.begin(), vec.end(), [&count](int &x) { x = ++count; });
    // std::for_each(se::unseq, vec.begin(), vec.end(), [&count](int &x) { x = ++count; });
    // std::for_each(se::par_unseq, vec.begin(), vec.end(), [&count](int &x) { x = ++count; });

    std::ranges::copy(vec, std::ostream_iterator<int>(std::cout, " "));
}