import <iostream>;
import <atomic>;

int main(int argc, char *argv[]) {
  std::atomic<double> atval{};

  atval.store(5.5);

  std::cout << "Current: " << atval.load() << std::endl;

  std::cout << "Using Exchange: " << atval.exchange(4.3) << std::endl;

  std::cout << "Current: " << atval.load() << std::endl;
}