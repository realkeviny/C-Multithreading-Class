import <execution>;
import <iostream>;
import <numeric>;
import <vector>;

namespace se = std::execution;
int main(int argc, char *argv[])
{
    std::vector<double> paper_scores{95.0, 88.5, 76.0, 92.0, 84.0};
    std::vector<double> weights{5., 4., 3., 2., 3.5};

    // try
    // {
    //     auto weighted_paper_score{std::inner_product(paper_scores.begin(), paper_scores.end(), weights.begin(),
    //     0.0)}; auto total_weight{std::accumulate(weights.begin(), weights.end(), 0., [](double x, double y) {
    //         throw std::invalid_argument("Exception Coming!");
    //         return true;
    //     })};
    //     std::cout << "Weighted Mean: " << weighted_paper_score / total_weight << std::endl;
    // }
    // catch (const std::exception &exp)
    // {
    //     std::cerr << "Exception Caught: " << exp.what() << std::endl;
    // }

    // With Execution Policy
    try
    {
        auto weighted_paper_score{
            std::transform_reduce(se::par_unseq, paper_scores.begin(), paper_scores.end(), weights.begin(), 0.0)};

        auto total_weight{std::reduce(se::par_unseq, weights.begin(), weights.end(), 0., [](double x, double y) {
            throw std::invalid_argument("Exception Coming!");
            return true;
        })};

        std::cout << "Weighted Mean: " << weighted_paper_score / total_weight << std::endl;
    }
    catch (const std::exception &exp)
    {
        std::cerr << "Exception Caught: " << exp.what() << std::endl;
    }
}