import <iostream>;
import <thread>;
import <condition_variable>;
import <string>;
import <chrono>;

using namespace std::literals;

// TODO: Modify your program so that it is not affected by lost wakeups
// Modify your program so that there are three reader threads
// Modify the reader 's task function to display the thread' s ID
// Modify the writer's task function so that it
// Calls notify_one() once
// Calls notify_one() three times
// Calls notify_all() once

std::mutex mtx;
std::condition_variable cond_var;
bool notified{};
int wake_count{};

void writer(std::string &data_received) {
  {
    std::cout << "Writer thread is locking mutex" << std::endl;
    std::lock_guard data_mod_guard(mtx);

    std::cout << "Writer has locked the mutex" << std::endl;
    std::this_thread::sleep_for(2s);

    std::cout << "Writer is modifying data" << std::endl;
    data_received = "Now!";
    notified = true;
  }

  std::cout << "Writer is waking another thread up" << std::endl;
  // cond_var.notify_one();
  for (size_t i{}; i < 3; ++i) {
    cond_var.notify_one();
  }
  // cond_var.notify_all();
}

void reader(const std::string &data_received) {
  std::cout << "Reader thread is locking mutex..." << std::endl;
  std::unique_lock uniq_rd_lock(mtx);
  std::cout << "Reader has locked the mutex...." << std::endl;

  std::cout << "Reader is waiting...." << std::endl;
  cond_var.wait(uniq_rd_lock, [] { return notified; });
  std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
  // Reading Data
  std::cout << "Modified Data: " << data_received << std::endl;

  ++wake_count;
  std::cout << "Wake count: " << wake_count << std::endl;
  std::this_thread::sleep_for(300ms);
}

int main(int argc, char *argv[]) {
  std::string str{"Current"};
  std::cout << "str initial state: " << str << std::endl;
  std::jthread writing(writer, std::ref(str));
  std::this_thread::sleep_for(500ms);
  std::jthread reading1(reader, std::ref(str));
  // std::this_thread::sleep_for(100ms);
  std::jthread reading2(reader, std::ref(str));
  // std::this_thread::sleep_for(100ms);
  std::jthread reading3(reader, std::ref(str));
  // std::this_thread::sleep_for(100ms);

  // writing.join();
  // reading1.join();
  // reading2.join();
  // reading3.join();
}