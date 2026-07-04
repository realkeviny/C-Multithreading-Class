import <future>;
import <iostream>;
import <numeric>;
import <vector>;
import <random>;
import <algorithm>;

std::mt19937 mt;
std::uniform_real_distribution<double> dist(0, 100);

// Compute the sum of a range of elements
// Process each one of these subsets
double acc(double *beg, double *end)
{
    return std::accumulate(beg, end, 0.0);
}

// Actual Calculation
/*
double add_parallel(std::vector<double> &vec)
{
    // Get the address of the first element in the vector
    auto first_ele{&vec[0]};

    // Number of elements
    auto size{vec.size()};

    // Start Threads
    // Pass the range for the subset as the argument to the task function
    // Each of the part has size/4 elements
    auto dfut1{std::async(std::launch::async, acc, first_ele, first_ele + size / 4)};
    auto dfut2{std::async(std::launch::async, acc, first_ele + size / 4, first_ele + 2 * size / 4)};
    auto dfut3{std::async(std::launch::async, acc, first_ele + 2 * size / 4, first_ele + 3 * size / 4)};
    auto dfut4{std::async(std::launch::async, acc, first_ele + 3 * size / 4, first_ele + size)};

    // Reduce
    // Combine the results for each subset
    return dfut1.get() + dfut2.get() + dfut3.get() + dfut4.get();
}
*/

// Using Packaged_task
double add_parallel(std::vector<double> &vec)
{
    using task_type = double(double *, double *);

    // Packaged_tasks for each threads
    std::packaged_task<task_type> pt1(acc);
    std::packaged_task<task_type> pt2(acc);
    std::packaged_task<task_type> pt3(acc);
    std::packaged_task<task_type> pt4(acc);

    auto pfut1{pt1.get_future()};
    auto pfut2{pt2.get_future()};
    auto pfut3{pt3.get_future()};
    auto pfut4{pt4.get_future()};
    // Get the address of the first element in the vector
    auto first_ele{&vec[0]};

    // Number of elements
    auto size{vec.size()};
    // Start Threads
    // Pass the range for the subset as the argument to the task function
    // Each of the part has size/4 elements
    std::jthread thr1{std::move(pt1), first_ele, first_ele + size / 4};
    std::jthread thr2{std::move(pt2), first_ele + size / 4, first_ele + 2 * size / 4};
    std::jthread thr3{std::move(pt3), first_ele + 2 * size / 4, first_ele + 3 * size / 4};
    std::jthread thr4{std::move(pt4), first_ele + 3 * size / 4, first_ele + size};

    // thr1.join();
    // thr2.join();
    // thr3.join();
    // thr4.join();

    // Reduce
    // Combine the results for each subset
    return pfut1.get() + pfut2.get() + pfut3.get() + pfut4.get();
}

int main(int argc, char *argv[])
{
    // Populate a vector with elements 1~16
    std::vector<double> dvec(16);
    std::iota(dvec.begin(), dvec.end(), 1.0);

    // Populate a vector with 10,000 random elements
    std::vector<double> dranvec(10'000);
    std::generate(dranvec.begin(), dranvec.end(), []() { return dist(mt); });

    std::cout << "Sum of the first 16 integers: " << add_parallel(dvec) << std::endl;
    std::cout << "Sum of the 10'000 randoms: " << add_parallel(dranvec) << std::endl;
}
