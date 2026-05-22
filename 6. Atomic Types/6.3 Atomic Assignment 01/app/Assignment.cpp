#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

struct Human {
  std::string name;
  int age;

  void print() {
    std::cout << "Name: " << name << " ,Age: " << age << std::endl;
  }
};

std::atomic<Human *> pHuman{nullptr};
std::mutex mtx;

void process() {
  if (!pHuman) {
    std::lock_guard<std::mutex> lck_guard(mtx);
    if (!pHuman) {
      pHuman = new Human{"Apollo", 34};
    }
  }
  Human *ptr = pHuman;
  ptr->print();
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> threads;
  for (size_t i{}; i < 20; ++i) {
    threads.emplace_back(std::thread(process));
  }

  for (auto &thr : threads) {
    thr.join();
  }
}
