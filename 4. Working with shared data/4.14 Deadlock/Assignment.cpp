import <iostream>;
import <thread>;
import <mutex>;
import <vector>;
import <chrono>;

using namespace std::literals;

// TODO:Write a program which causes two threads to deadlock
std::mutex mtx1;
std::mutex mtx2;

/*
void task1() {
  std::cout << "Thread A attmpeting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx1);
  std::cout << "Thread A has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attmpeting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx2);
  std::cout << "Thread A has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attmpeting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attmpeting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx2);
  std::cout << "Thread B has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attmpeting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx1);
  std::cout << "Thread B has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attmpeting to unlock every mutexes!" << std::endl;
}
*/

// TODO:Implement your solution, and verify that the program is no longer
// affected by deadlock

void task1() {
  std::cout << "Thread A attmpeting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx1);
  std::cout << "Thread A has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attmpeting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx2);
  std::cout << "Thread A has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread A attmpeting to unlock every mutexes!" << std::endl;
}

void task2() {
  std::cout << "Thread B attmpeting to lock mutex 1..." << std::endl;
  std::lock_guard<std::mutex> lck1(mtx1);
  std::cout << "Thread B has locked mutex 1..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attmpeting to lock mutex 2..." << std::endl;
  std::lock_guard<std::mutex> lck2(mtx2);
  std::cout << "Thread B has locked mutex 2..." << std::endl;
  std::this_thread::sleep_for(50ms);
  std::cout << "Thread B attmpeting to unlock every mutexes!" << std::endl;
}

int main(int argc, char *argv[]) {
  std::jthread jtA(task1);
  std::jthread jtB(task2);
}
