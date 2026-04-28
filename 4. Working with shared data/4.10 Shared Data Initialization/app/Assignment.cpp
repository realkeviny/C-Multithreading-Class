import new_singleton;
import <iostream>;
import <vector>;
import <thread>;

// TraditionalSingleton *TraditionalSingleton::tradsing{};

void taskFunc() {
  NewSingleton &object{getInstance()};
  std::cout << &object << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector<std::jthread> joinableThreads;
  for (int i = 0; i < 20; ++i) {
    joinableThreads.emplace_back(std::jthread(taskFunc));
  }
}