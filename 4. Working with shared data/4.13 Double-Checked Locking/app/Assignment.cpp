import <iostream>;
import <thread>;
import <mutex>;
import <vector>;

struct Human {
  std::string name;
  int age;

  void print() {
    std::cout << "Name: " << name << " ,Age: " << age << std::endl;
  }
};

Human *rigen{};
std::once_flag flag;
std::mutex mtx;

void initializer() {
  std::call_once(flag, []() { rigen = new Human; });
  std::unique_lock<std::mutex> print_lock(mtx);
  rigen->print();
}

int main(int argc, char *argv[]) {
  std::vector<std::thread> threads;
  for (size_t i{}; i < 5; ++i) {
    threads.emplace_back(std::thread(initializer));
  }

  for (auto &thr : threads) {
    thr.join();
  }
}
