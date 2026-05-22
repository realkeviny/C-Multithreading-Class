import <vector>;
import <iostream>;
import <thread>;
import <atomic>;

// Atomic Type
/*
std::atomic<int> counter{}; // An atomic variable of type int

void task() {
  for (size_t i{}; i < 100'000; ++i) {
    ++counter;
  }
}
*/

// A confusion----Volatile
volatile int counter{}; // No effect on thread safety!

void task() {
  for (size_t i{}; i < 100'000; ++i) {
    ++counter;
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> tasks;

  for (size_t i{}; i < 10; ++i) {
    tasks.push_back(std::thread(task));
  }

  for (auto &thr : tasks) {
    thr.join();
  }

  std::cout << counter << '\n';
}