import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;

using namespace std::literals;

std::mutex mt1;
std::mutex mt2;

// Livelock
/*
void funcA()
{
    std::this_thread::sleep_for(10ms);
    bool locked{false};
    while (!locked)
    {
        std::lock_guard<std::mutex> lck_guard(mt1);
        std::cout << "After you, Kelf!\n";
        std::this_thread::sleep_for(2s);
        locked = mt2.try_lock();
    }
    if (locked)
    {
        std::cout << "Thread A has locked both mutexes\n";
    }
}

void funcB()
{
    bool locked{false};
    while (!locked)
    {
        std::lock_guard<std::mutex> lck_guard2(mt2);
        std::cout << "After you, Jenna!\n";
        std::this_thread::sleep_for(2s);
        locked = mt1.try_lock();
    }
    if (locked)
    {
        std::cout << "Thread B has locked both mutexes\n";
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(funcA);
    std::this_thread::sleep_for(10ms);
    std::thread t2(funcB);

    t1.join();
    t2.join();
    return 0;
}
*/

// Avoidance 1: Using scoped_lock/std::lock()
void funcA()
{
    std::this_thread::sleep_for(10ms);
    std::cout << "After you, Kelf!\n";
    std::scoped_lock scoped_lck(mt1, mt2);
    std::this_thread::sleep_for(2s);
    std::cout << "Thread A has locked both mutexes\n";
}

void funcB()
{
    std::cout << "After you, Jenna!\n";
    std::scoped_lock scoped_lck(mt2, mt1);
    std::this_thread::sleep_for(2s);
    std::cout << "Thread B has locked both mutexes\n";
}

int main(int argc, char const *argv[])
{
    std::thread t1(funcA);
    std::this_thread::sleep_for(10ms);
    std::thread t2(funcB);

    t1.join();
    t2.join();
    return 0;
}