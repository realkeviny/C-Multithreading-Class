// Write a program to demonstrate the use of std::accumulate()
// Store the damage dealt in each attack and use std::accumulate() to calculate the total damage.
// Rewrite your program to use a parallel execution policy

/*
import <iostream>;
import <vector>;
import <numeric>;
import <execution>;

int main(int argc, char *argv[])
{
    std::vector<int> RanceAttack{135, 248, 197, 326, 289, 175};
    std::cout << "Battle Record" << std::endl;
    std::cout << "--------------" << std::endl;
    for (size_t i{}; i < RanceAttack.size(); ++i)
    {
        std::cout << "Attack " << i + 1 << ": " << RanceAttack[i] << std::endl;
    }
    // auto TotalDamage{std::accumulate(RanceAttack.begin(), RanceAttack.end(), 0)};
    auto TotalDamage{std::reduce(std::execution::par_unseq, RanceAttack.begin(), RanceAttack.end(), 0)};

    std::cout << "Total Damage : " << TotalDamage << std::endl;

    double BattleDuration{};
    std::cout << "Input Battle Duration: " << std::endl;
    std::cin >> BattleDuration;

    std::cout << "Battle Duration (seconds): " << BattleDuration << std::endl;
    if (BattleDuration > 0)
    {
        std::cout << "Average DPS : " << static_cast<double>(TotalDamage) / BattleDuration << '\n';
    }
    else
    {
        std::cout << "Battle duration must be greater than 0.\n";
    }
}
*/

/**
Requirement
Create a program that simulates a bank account transaction log.
Store deposits and withdrawals (positive and negative values).
Use std::partial_sum() to compute the account balance over time.
Display balance after each transaction.
*/

import <iostream>;
import <vector>;
import <numeric>;
import <execution>;

int main(int argc, char *argv[])
{
    std::vector<int> transactions{+1000, -200, +500, -150};
    std::vector<int> balance(transactions.size());

    // Using a different standard C++ function, rewrite your program to use a parallel execution policy
    // std::partial_sum(transactions.begin(), transactions.end(), balance.begin());
    std::inclusive_scan(std::execution::par, transactions.begin(), transactions.end(), balance.begin());

    for (size_t i{}; i < balance.size(); ++i)
    {
        std::cout << "After transaction " << i + 1 << " Balance " << balance[i] << std::endl;
    }
}