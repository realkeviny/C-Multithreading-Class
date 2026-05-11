import <iostream>;
import <thread>;
import <condition_variable>;
import <string>;
import <chrono>;

using namespace std::literals;

std::mutex mtx;
std::condition_variable cond_var;

void writer(std::string &data_received) {
  {
    std::cout << "Writer thread is locking mutex" << std::endl;
    std::lock_guard data_mod_guard(mtx);

    std::cout << "Writer has locked the mutex" << std::endl;
    std::this_thread::sleep_for(2s);

    std::cout << "Writer is modifying data" << std::endl;
    data_received = "Now!";
  }

  std::cout << "Writer is waking another thread up" << std::endl;
  cond_var.notify_one();
}

void reader(const std::string &data_received) {
  std::cout << "Reader thread is locking mutex..." << std::endl;
  std::unique_lock uniq_rd_lock(mtx);
  std::cout << "Reader has locked the mutex...." << std::endl;

  std::cout << "Reader is waiting...." << std::endl;
  cond_var.wait(uniq_rd_lock);

  // Reading Data
  std::cout << "Modified Data: " << data_received << std::endl;
}

int main(int argc, char *argv[]) {
  std::string str{"Current"};
  std::cout << "str initial state: " << str << std::endl;
  std::jthread writing(writer, std::ref(str));
  std::this_thread::sleep_for(3s);
  std::jthread reading(reader, std::ref(str));
}