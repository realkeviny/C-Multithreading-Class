#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Test {
public:
  void func() {}
};

std::atomic<Test *> ptest{};
std::mutex mtx;

void task() {
  if (!ptest) {
    std::lock_guard<std::mutex> lck_guard(mtx);
    if (!ptest) {
      ptest = new Test;
    }
  }
  Test *ptr = ptest;
  ptr->func();
}

int main(int argc, char *argv[]) {

  std::vector<std::thread> tasks;

  for (size_t i{}; i <= 10; ++i) {
    tasks.push_back(std::thread(task));
  }

  for (auto &thr : tasks) {
    thr.join();
  }
}