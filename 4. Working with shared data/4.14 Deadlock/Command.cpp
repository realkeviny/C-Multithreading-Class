import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;

using namespace std::literals;

std::mutex mt1;
std::mutex mt2;

/*
void funcA()
{
    std::cout << "Thread A trying to lock mutex 1..." << std::endl;
    std::lock_guard<std::mutex> lck_guard(mt1);
    std::cout << "Thread A has locked mutex 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A trying to lock mutex 2..." << std::endl;
    std::lock_guard<std::mutex> lck_guard2(mt2);
    std::cout << "Thread A has locked mutex 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A has release all mutexes!" << std::endl;
}

void funcB()
{
    std::cout << "Thread B trying to lock mutex 2..." << std::endl;
    std::lock_guard<std::mutex> lck_guard2(mt2);
    std::cout << "Thread B has locked mutex 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B trying to lock mutex 1..." << std::endl;
    std::lock_guard<std::mutex> lck_guard(mt1);
    std::cout << "Thread B has locked mutex 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B has release all mutexes!" << std::endl;
}
*/

// Simplest Avoidance
void funcA()
{
    std::cout << "Thread A trying to lock mutex 1..." << std::endl;
    std::lock_guard<std::mutex> lck_guard(mt1);
    std::cout << "Thread A has locked mutex 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A trying to lock mutex 2..." << std::endl;
    std::lock_guard<std::mutex> lck_guard2(mt2);
    std::cout << "Thread A has locked mutex 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread A has release all mutexes!" << std::endl;
}

void funcB()
{
    std::cout << "Thread B trying to lock mutex 1..." << std::endl;
    std::lock_guard<std::mutex> lck_guard(mt1);
    std::cout << "Thread B has locked mutex 1..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B trying to lock mutex 2..." << std::endl;
    std::lock_guard<std::mutex> lck_guard2(mt2);
    std::cout << "Thread B has locked mutex 2..." << std::endl;
    std::this_thread::sleep_for(50ms);
    std::cout << "Thread B has release all mutexes!" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::jthread jt1(funcA);
    std::jthread jt2(funcB);
    return 0;
}
