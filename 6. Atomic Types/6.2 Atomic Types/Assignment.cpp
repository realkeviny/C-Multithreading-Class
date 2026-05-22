#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

// std::atomic<int> counter{};
volatile int counter{};

void task() {
  for (int i = 0; i < 100'000; ++i) {
    ++counter;
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> threads;
  for (size_t i = 0; i < 20; ++i) {
    threads.emplace_back(std::thread(task));
  }

  for (auto &thr : threads) {
    thr.join();
  }
  std::cout << "Final Value: " << counter << std::endl;
}