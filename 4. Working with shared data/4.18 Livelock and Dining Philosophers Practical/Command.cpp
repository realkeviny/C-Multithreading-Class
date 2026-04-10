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

// Timeout for a philosopher who has picked up 1 fork will put it down again
//  if they can't pick up the other fork they need
constexpr auto time_out{time_to_think};

/**
 * Array of mutexes, with 1 element for each fork.
 * If a philosopher thread wants to pick up a fork,
 * it has to lock the element of this mutex which corresponds to that fork.
 */
std::array<std::mutex, num_of_forks> fork_mutex;

// Protect output.
std::mutex printing_mutex;

// Display information about the interactions with a fork
void print(int n, std::string_view msg, int nfork)
{
    std::lock_guard<std::mutex> printing_lock(printing_mutex);
    std::cout << "Philosopher " << names[n] << msg << nfork << std::endl;
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

    print(nphilo, "\'s left fork is ", lfork);
    print(nphilo, "\'s right fork is ", rfork);
    print(nphilo, "\'s thinking....");

    std::this_thread::sleep_for(time_to_think);

    // Attempt to eat by trying to reach left fork
    print(nphilo, " reaches for fork number ", lfork);

    // Attempt to pick up left fork
    bool locked{false};

    while (!locked)
    {
        fork_mutex[lfork].lock();
        print(nphilo, " picks up fork ", lfork);
        print(nphilo, "\'s thinking....");

        // Succeeded - now try to pick up the right fork
        std::this_thread::sleep_for(time_to_think);
        print(nphilo, " reaches for fork number ", rfork);

        locked = fork_mutex[rfork].try_lock();

        if (!locked)
        {
            print(nphilo, " puts down fork ", lfork);
            std::this_thread::sleep_for(time_to_think);
            fork_mutex[lfork].unlock();
        }
    }

    // Succeeded - this philosopher can now eat
    print(nphilo, " picks up fork ", rfork);
    print(nphilo, " is eating...");
    ++mouthfuls[nphilo];

    std::this_thread::sleep_for(time_to_eat);

    print(nphilo, " puts down fork ", lfork);
    print(nphilo, " puts down fork ", rfork);
    print(nphilo, " is thinking...");

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