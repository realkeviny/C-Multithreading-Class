import <iostream>;
import <thread>;
import <mutex>;
import <vector>;
import <string>;
import <chrono>;
import <array>;
import <string_view>;

using namespace std::literals;

constexpr int num_of_forks{5};
constexpr int num_of_philosophers{num_of_forks};
std::array<std::string, num_of_philosophers> names{"Plato", "Aristotle", "Kant", "Nietzsche", "Confucius"};

// Keep track of how many mouthfuls each philosopher gets(How many times they are able to eat).
std::array<int, num_of_philosophers> mouthfuls{};

// Time for thinking.
constexpr auto time_to_think{2s};
// Time for eating.
constexpr auto time_to_eat{1s};

/**
 * Array of mutexes, with 1 element for each fork.
 * If a philosopher thread wants to pick up a fork,
 * it has to lock the element of this mutex which corresponds to that fork.
 */
std::array<std::mutex, num_of_forks> fork_mutex;

// Protect output.
std::mutex printing_mutex;

// Display information about the interactions with a fork
void print(int n, std::string_view msg, int fork_no)
{
    std::lock_guard<std::mutex> printing_lock(printing_mutex);
    std::cout << "Philosopher " << names[n] << msg << fork_no << std::endl;
}

// Display information about the philosopher's state
void print(int n, std::string_view msg)
{
    std::lock_guard<std::mutex> printing_lock(printing_mutex);
    std::cout << "Philosopher " << names[n] << msg << std::endl;
}

// Thread function for philosopher
void dine(int nphilo)
{
    int lfork{nphilo};
    int rfork{(nphilo + 1) % num_of_forks};

    print(nphilo, "\'s left fork is fork number ", lfork);
    print(nphilo, "\'s right fork is fork number ", rfork);
    print(nphilo, "\'s thinking....");

    std::this_thread::sleep_for(time_to_think);

    // Attempt to eat by trying to reach the fork on the left
    print(nphilo, " reaches for fork number ", lfork);

    fork_mutex[lfork].lock();
    print(nphilo, " picks up fork number ", lfork);
    print(nphilo, "\'s thinking....");

    // Attempt to eat by trying to reach the fork on the right
    std::this_thread::sleep_for(time_to_think);

    print(nphilo, " reaches for fork number ", rfork);
    fork_mutex[rfork].lock();
    print(nphilo, " picks up fork number ", rfork);
    print(nphilo, "\'s eating....");

    // Eating...
    std::this_thread::sleep_for(time_to_eat);
    print(nphilo, " puts down fork number ", lfork);
    print(nphilo, " puts down fork number ", rfork);
    fork_mutex[lfork].unlock();
    fork_mutex[rfork].unlock();
    std::this_thread::sleep_for(time_to_think);
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> philos;

    for (size_t i = 0; i < num_of_philosophers; ++i)
    {
        philos.push_back(std::move(std::thread(dine, i)));
    }

    for (auto &philo : philos)
    {
        philo.join();
    }

    for (size_t i = 0; i < num_of_philosophers; ++i)
    {
        std::cout << "Philosopher " << names[i];
        std::cout << " had " << mouthfuls[i] << " mouthfuls\n";
    }

    return 0;
}