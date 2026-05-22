#include <iostream>
#include <mutex>
#include <thread>
#include <vector>


int counter{0};

std::mutex mtx;

void task() {
  for (int i = 0; i < 100'000; ++i) {
    std::lock_guard<std::mutex> guard(mtx);
    ++counter;
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> threads;
  for (size_t i = 0; i < 10; ++i) {
    threads.emplace_back(std::thread(task));
  }

  for (auto &thr : threads) {
    thr.join();
  }
  std::cout << "Final Value: " << counter << std::endl;
}