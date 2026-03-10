import <iostream>;
import <algorithm>;
import <vector>;

int main(int argc, char const *argv[])
{
    std::vector<int> ivec{2, 6, 5, 4, 1};

    std::cout << "Elements: ";
    for (auto &i : ivec)
    {
        std::cout << i << ", ";
    }
    std::cout << " ";

    int radix = 3;

    auto n_evens = std::count_if(ivec.cbegin(), ivec.cend(), [radix](int n)
                                { return n % radix == 0; });
    std::cout << "The vector has " << n_evens << " elements with even values" << std::endl;
    return 0;
}
