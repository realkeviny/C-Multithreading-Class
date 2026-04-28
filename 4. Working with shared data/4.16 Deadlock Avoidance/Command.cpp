import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;

using namespace std::literals;

std::mutex mt1;
std::mutex mt2;

// C++ 17 scoped_lock
/*
void funcA()
{
    std::cout << "Thread A trying to lock mutex 1 and 2..." << std::endl;
    std::scoped_lock scoped_lck(mt1, mt2);
    std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A has released mutexes 1 and 2..." << std::endl;
}

void funcB()
{
    std::cout << "Thread B trying to lock mutex 2 and 1..." << std::endl;
    std::scoped_lock scoped_lck(mt2, mt1);
    std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B has released mutexes 2 and 1..." << std::endl;
}
*/

// C++ 11 lock
/*
void funcA()
{
    std::cout << "Thread A trying to lock mutex 1 and 2..." << std::endl;
    std::lock(mt1, mt2);
    std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;

    // Adopt locks
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::adopt_lock);
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::adopt_lock);
    std::cout << "Thread A has adopted the locks..." << std::endl;

    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A has released mutexes 1 and 2..." << std::endl;
}

void funcB()
{
    std::cout << "Thread B trying to lock mutex 2 and 1..." << std::endl;
    std::lock(mt2, mt1);
    std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;

    // Adopt locks
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::adopt_lock);
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::adopt_lock);
    std::cout << "Thread B has adopted the locks..." << std::endl;

    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B has released mutexes 2 and 1..." << std::endl;
}
*/

// Deferring Locks
/*
void funcA()
{
    // Deferring locks
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::defer_lock);
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::defer_lock);

    std::cout << "Thread A trying to lock mutex 1 and 2..." << std::endl;
    std::lock(uniq_lck1, uniq_lck2);
    std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A has released mutexes 1 and 2..." << std::endl;
}

void funcB()
{
    // Adopt locks
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::defer_lock);
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::defer_lock);

    std::cout << "Thread B trying to lock mutex 2 and 1..." << std::endl;
    std::lock(uniq_lck2, uniq_lck1);
    std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B has released mutexes 2 and 1..." << std::endl;
}
*/

// try_lock()
void funcA()
{
    // Deferring locks
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::defer_lock);
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::defer_lock);

    std::cout << "Thread A trying to lock mutex 1 and 2..." << std::endl;
    auto idx{std::try_lock(uniq_lck1, uniq_lck2)};
    if (idx != -1)
    {
        std::cout << "try_lock failed on mutex with index " << idx << std::endl;
    }
    else
    {
        std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;
        std::this_thread::sleep_for(50ms);
        std::cout << "Thread A has released mutexes 1 and 2..." << std::endl;
    }
}

void funcB()
{
    // Adopt locks
    std::unique_lock<std::mutex> uniq_lck2(mt2, std::defer_lock);
    std::unique_lock<std::mutex> uniq_lck1(mt1, std::defer_lock);

    std::cout << "Thread B trying to lock mutex 2 and 1..." << std::endl;
    auto idx{std::try_lock(uniq_lck2, uniq_lck1)};
    if (idx != -1)
    {
        std::cout << "try_lock failed on mutex with index " << idx << std::endl;
    }
    else
    {
        std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;
        std::this_thread::sleep_for(50ms);
        std::cout << "Thread B has released mutexes 2 and 1..." << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(funcA);
    std::thread t2(funcB);
    t1.join();
    t2.join();
    return 0;
}
