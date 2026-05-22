import <vector>;
import <iostream>;
import <thread>;
import <mutex>;

std::mutex mtx;
int counter{};

void task() {
  for (size_t i{}; i < 100'000; ++i) {
    std::lock_guard lck_guard(mtx);
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