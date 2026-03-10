
/**
 * fizzbuzz: fizz && buzz
 * fizz: num % 3 == 0
 * buzz: num % 5 == 0
 * Circular Traversal: Current Index = (Current Iteration Step - 1) % Size of array （1-based)
 * For 0-based, it's Current Iteration Step % Size of array
 */

import <string_view>;
import <thread>;
import <iostream>;
import <vector>;

void fizzbuzz(const std::vector<std::string> &svec, int play_times)
{
    for (int num = 1; num <= play_times; ++num)
    {
        std::string_view current_player{svec[(num - 1) % svec.size()]};
        if (num % 3 == 0 && num % 5 == 0)
        {
            std::cout << current_player << " says fizzbuzz!" << std::endl;
        }
        else if (num % 3 == 0)
        {
            std::cout << current_player << " says fizz!" << std::endl;
        }
        else if (num % 5 == 0)
        {
            std::cout << current_player << " says buzz!" << std::endl;
        }
        else
        {
            std::cout << current_player << " says " << num << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Program can only be called with 3 arguments like: " << std::endl;
        std::cerr << "program_name num_of_play_times" << std::endl;
        return -1;
    }
    std::vector<std::string> names{"Abdul", "Bart", "Claudia", "Divya"};
    std::thread execution_thread(fizzbuzz, std::ref(names), std::atoi(argv[1]));
    execution_thread.join();
    return 0;
}
