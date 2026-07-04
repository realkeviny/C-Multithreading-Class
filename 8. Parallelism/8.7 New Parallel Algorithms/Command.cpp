import <iostream>;
import <vector>;
import <numeric>;
import <ranges>;
import <algorithm>;
import <execution>;

namespace se = std::execution;
int main(int argc, char *argv[])
{
    // std::accumulate -> std::reduce
    /*
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7};
    std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, ","));
    std::cout << "\n";

    auto sum{std::accumulate(ivec.begin(), ivec.end(), 0)};
    auto sum{std::reduce(se::par, ivec.begin(), ivec.end(), 0)};
    std::cout << "The sum of the element is " << sum << std::endl;
    */

    // std::partial_sum() -> std::inclusive_scan() / std::exclusive_scan()
    /*
    std::vector<int> ivec{1, 2, 3, 4};
    std::vector<int> ivec2(ivec.size());

    // std::partial_sum(ivec.begin(), ivec.end(), ivec2.begin());
    // std::inclusive_scan(se::par, ivec.begin(), ivec.end(), ivec2.begin());
    std::exclusive_scan(se::par_unseq, ivec.begin(), ivec.end(), ivec2.begin(), -1);

    // Equivalent Usage
    std::vector<int> ivec3{-1, 1, 2, 3};
    std::vector<int> ivec4(ivec.size());
    std::inclusive_scan(ivec3.begin(), ivec3.end(), ivec4.begin());

    std::cout << "Vector Elements: ";
    std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Exclusive scan vector elements: ";
    std::ranges::copy(ivec2, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Inclusive scan vector elements: ";
    std::ranges::copy(ivec4, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;
    */

    // std::transform
    /*
    std::vector<int> ivec{1, 2, 3, 4};
    std::vector<int> ivec2;

    std::transform(ivec.begin(), ivec.end(), std::back_inserter(ivec2), [](int n) { return 2 * n; });

    std::cout << "Vector Elements: ";
    std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Output vector elements: ";
    std::ranges::copy(ivec2, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;
    */

    // Binary Predicates
    /*
    std::vector<int> ivec{1, 2, 3, 4};
    std::vector<int> ivec2{5, 6, 7, 8};
    std::vector<int> ivecr;

    std::transform(ivec.begin(), ivec.end(), ivec2.begin(), std::back_inserter(ivecr),
                   [](int n1, int n2) { return n1 + n2; });

    std::cout << "Vector 1 Elements: ";
    std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Vector 2 Elements: ";
    std::ranges::copy(ivec2, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Output vector elements: ";
    std::ranges::copy(ivecr, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;
    */

    // Transform_Reduce 1
    /*
    std::vector<int> ivec{1, 2, 3, 4, 5};
    std::vector<int> ivec2{5, 4, 3, 2, 1};

    // auto result{std::inner_product(ivec.begin(), ivec.end(), ivec2.begin(), 0)};
    auto result{std::transform_reduce(ivec.begin(), ivec.end(), ivec2.begin(), 0)};

    std::cout << "Vector 1 Elements: ";
    std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Vector 2 Elements: ";
    std::ranges::copy(ivec2, std::ostream_iterator<int>(std::cout, ","));
    std::cout << std::endl;

    std::cout << "Result: " << result << std::endl;
    */

    // Transform_reduce 2
    std::vector<double> expected{0.1, 0.2, 0.4, 0.6, 0.8};
    std::vector<double> experimented{0.09, 0.31, 0.25, 0.62, 0.81};

    auto max_diff{std::transform_reduce(
        se::par, std::begin(expected), std::end(expected), std::begin(experimented), 0.0,
        [](auto diff1, auto diff2) { return std::max(diff1, diff2); },
        [](auto exp, auto act) { return std::abs(act - exp); })};

    std::cout << "Max Difference: " << max_diff << std::endl;
}
