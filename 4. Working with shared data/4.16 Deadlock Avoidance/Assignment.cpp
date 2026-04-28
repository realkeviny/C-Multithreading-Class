import <iostream>;
import <thread>;
import <mutex>;
import <vector>;
import <chrono>;

using namespace std::literals;

// TODO:Write a program which causes two threads to deadlock
std::mutex mtx1;
std::mutex mtx2;

/*
void task1() {
  std::cout << "Thread A attempting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx1);
  std::cout << "Thread A has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx2);
  std::cout << "Thread A has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attempting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx2);
  std::cout << "Thread B has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx1);
  std::cout << "Thread B has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to unlock every mutexes!" << std::endl;
}
*/

// TODO:Implement your solution, and verify that the program is no longer
// affected by deadlock

//(C++ 17) std::scoped_lock
/*
void task1() {
  std::cout << "Thread A attempting to lock mutex 1 and 2..." << std::endl;
  std::scoped_lock scop_lck(mtx1, mtx2);
  std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attempting to lock mutex 2 and 1..." << std::endl;
  std::scoped_lock scop_lck(mtx2, mtx1);
  std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to unlock every mutexes!" << std::endl;
}
*/

//(C++ 11) std::lock
/*
void task1() {
  std::cout << "Thread A attempting to lock mutex 1 and 2..." << std::endl;
  std::lock(mtx1, mtx2);
  std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to unlock every mutexes!" << std::endl;
  mtx1.unlock();
  mtx2.unlock();
}

void task2() {
  std::cout << "Thread B attempting to lock mutex 2 and 1..." << std::endl;
  std::lock(mtx2, mtx1);
  std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to unlock every mutexes!" << std::endl;
  mtx2.unlock();
  mtx1.unlock();
}
*/

// Hierarchical Mutex
/*
class hierarchical_mutex {
private:
  std::mutex internal_mutex;
  const unsigned long hierarchy_value;
  unsigned long previous_hierarchy_value;

  static thread_local unsigned long this_thread_hierarchy_value;

  void check_for_hierarchy_violation() {
    if (this_thread_hierarchy_value >= hierarchy_value) {
      throw std::logic_error("mutex hierarchy violated");
    }
  }

  void update_hierarchy_value() {
    previous_hierarchy_value = this_thread_hierarchy_value;
    this_thread_hierarchy_value = hierarchy_value;
  }

public:
  explicit hierarchical_mutex(unsigned long value)
      : hierarchy_value(value), previous_hierarchy_value(0) {}

  void lock() {
    check_for_hierarchy_violation();
    internal_mutex.lock();
    update_hierarchy_value();
  }

  void unlock() {
    this_thread_hierarchy_value = previous_hierarchy_value;
    internal_mutex.unlock();
  }
};

thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(0);
hierarchical_mutex hmtx1(30);
hierarchical_mutex hmtx2(70);

void task1() {
  std::cout << "Thread A attempting to lock mutex 1..." << std::endl;
  std::lock_guard<hierarchical_mutex> lck1(hmtx1);
  std::cout << "Thread A has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to lock mutex 2..." << std::endl;
  std::lock_guard<hierarchical_mutex> lck2(hmtx2);
  std::cout << "Thread A has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attempting to lock mutex 2..." << std::endl;
  std::lock_guard<hierarchical_mutex> lck1(hmtx1);
  std::cout << "Thread B has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to lock mutex 1..." << std::endl;
  std::lock_guard<hierarchical_mutex> lck2(hmtx2);
  std::cout << "Thread B has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to unlock every mutexes!" << std::endl;
}
*/

// TODO: Rewrite this code to use std::unique_lock's defer_lock option
void task1() {
  std::cout << "Thread A attempting to lock mutex 1 and 2..." << std::endl;

  std::unique_lock<std::mutex> lk1(mtx1, std::defer_lock);
  std::unique_lock<std::mutex> lk2(mtx2, std::defer_lock);
  std::cout << "Unique locks for mutexes created!" << std::endl;

  std::lock(lk1, lk2);
  std::cout << "Thread A has locked mutex 1 and 2..." << std::endl;

  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attempting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attempting to lock mutex 2 and 1..." << std::endl;
  std::unique_lock<std::mutex> lk1(mtx2, std::defer_lock);
  std::unique_lock<std::mutex> lk2(mtx1, std::defer_lock);
  std::cout << "Unique locks for mutexes created!" << std::endl;

  std::lock(lk2, lk1);
  std::cout << "Thread B has locked mutex 2 and 1..." << std::endl;

  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attempting to unlock every mutexes!" << std::endl;
}

int main(int argc, char *argv[]) {
  std::jthread jtA(task1);
  std::jthread jtB(task2);
}
