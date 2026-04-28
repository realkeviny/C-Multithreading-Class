import <iostream>;
import <thread>;
import <chrono>;
import <mutex>;

using namespace std::literals;

std::mutex mt1, mt2;

void funcA() {
  std::this_thread::sleep_for(10ms);
  std::scoped_lock scp_lock(mt1, mt2);
  std::cout << "After you, Kelf!\n";
  std::cout << "Thread A has locked both mutexes\n";
}

void funcB() {
  bool locked{false};
  std::scoped_lock scp_lock(mt2, mt1);
  std::cout << "After you, Jenna!\n";
  std::cout << "Thread B has locked both mutexes\n";
}

int main(int argc, char *argv[]) {
  std::jthread jt1(funcA);
  std::jthread jt2(funcB);
}