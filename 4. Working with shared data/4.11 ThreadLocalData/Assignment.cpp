import <iostream>;
import <random>;
import <thread>;
import <vector>;
import <mutex>;

std::mutex mtx;
thread_local std::random_device rd;
thread_local std::mt19937 mt(rd()); // Random Number Engine

// Task Function
void func() {
  std::uniform_real_distribution<double> dist(0, 1);
  std::unique_lock<std::mutex> ulock(mtx);
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
  std::cout << "Number Acquired: ";
  for (size_t i = 0; i < 10; ++i) {
    std::cout << dist(mt) << (i < 9 ? ',' : '\n');
  }
  std::cout << std::endl;
  ulock.unlock();
}

int main(int argc, char const *argv[]) {
  std::vector<std::thread> threads;
  for (size_t i{}; i < 3; ++i) {
    threads.emplace_back(std::thread(func));
  }

  for (auto &thr : threads) {
    thr.join();
  }
  return 0;
}
