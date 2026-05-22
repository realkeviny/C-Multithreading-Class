import <iostream>;
import <atomic>;
import <thread>;
import <vector>;
import <chrono>;
import <mutex>;

// Spin Lock
/*
std::atomic_flag lock_critical_section{};

void task(int num) {
  while (lock_critical_section.test_and_set()) {
  }

  using namespace std::literals;
  std::this_thread::sleep_for(50ms);
  std::cout << "A task with argument: " << num << std::endl;

  lock_critical_section.clear();
}
*/

// Using Mutex
std::mutex mtx;
void task(int num) {
  std::lock_guard lck_guard(mtx);

  using namespace std::literals;
  std::this_thread::sleep_for(50ms);
  std::cout << "A task with argument: " << num << std::endl;
}

int main(int argc, char *argv[]) {

  // Atomic Basics
  /*
  std::atomic<int> x{};

  std::cout << "After Initialization: x = " << x << std::endl;

  // Atomic Assignment to x
  x = 2;

  // Atomic Assignment from x
  int y = x;

  std::cout << "After SAssignment: x = " << x << ", y = " << y << std::endl;

  x.store(7);
  std::cout << "After HAssignment: x = " << x.load() << std::endl;

  // Setting the value of x to be the value of y
  // And return the previous value of x
  std::cout << "After Exchange: x = " << x.exchange(y) << std::endl;
  std::cout << "After Exchange: x = " << x << ", y = " << y << std::endl;
  */

  std::vector<std::thread> tasks;

  for (size_t i{}; i <= 10; ++i) {
    tasks.push_back(std::thread(task, i));
  }

  for (auto &thr : tasks) {
    thr.join();
  }
}