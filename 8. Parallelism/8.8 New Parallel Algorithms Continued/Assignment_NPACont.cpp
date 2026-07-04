// Write a program to demonstrate std::transform()'s use

import <vector>;
import <iostream>;
import <ranges>;
import <algorithm>;
import <numeric>;
import <functional>;
import <execution>;

/*
int main(int argc, char *argv[])
{
    std::vector<int> source{1, 2, 3, 4, 5};
    std::vector<int> target;

    std::transform(source.begin(), source.end(), std::back_inserter(target), [](int num) { return std::pow(num, 2); });

    std::ranges::copy(target, std::ostream_iterator<int>(std::cout, " "));
}
*/

// Write a program to demonstrate std::transform() binary overload's use
/*
int main(int argc, char *argv[])
{
    std::vector<int> knowledge_points{80, 60, 90};
    std::vector<int> effort_points{50, 100, 70};
    std::vector<int> final_score;

    std::transform(knowledge_points.begin(), knowledge_points.end(), effort_points.begin(),
                   std::back_inserter(final_score),
                   [](int &kpoint, int &epoint) { return kpoint * 0.7 + epoint * 0.3; });

    std::ranges::copy(final_score, std::ostream_iterator<int>(std::cout, " "));
}
*/

// Write a program to demonstrate std::inner_product() 's use
/*
int main(int argc, char *argv[])
{
    std::vector<int> answers_A{1, 0, 1, 1, 0};
    std::vector<int> answers_B{1, 1, 1, 0, 0};
    int similarity{};

    similarity = std::inner_product(answers_A.begin(), answers_A.end(), answers_B.begin(), 0);

    std::cout << "Similarity: " << similarity << std::endl;
}
*/

// Write a program to demonstrate std::transform_reduce's use

int square_diff(int num1, int num2)
{
    return std::pow(num1 - num2, 2);
}

int main(int argc, char *argv[])
{
    std::function<int(int, int)> calc{square_diff};
    std::vector<int> vectors_A{1, 2, 3};
    std::vector<int> vectors_B{2, 4, 6};
    int difference{};

    difference = std::transform_reduce(std::execution::par, vectors_A.begin(), vectors_A.end(), vectors_B.begin(), 0,
                                       std::plus<int>(), calc);

    std::cout << "Difference: " << difference << std::endl;
}