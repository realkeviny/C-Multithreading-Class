import <iostream>;
import <thread>;
import <condition_variable>;
import <string>;
import <chrono>;

using namespace std::literals;

std::string shared_data;
std::mutex mtx;
std::condition_variable cond_var;
// Shared Boolean
bool condition{};

void reader() {
  // Lock the mutex
  std::cout << "Reader thread is locking mutex" << std::endl;
  // The condition variable has to be able to call unlock()
  std::unique_lock uniq_lck(mtx);
  std::cout << "Reader thread has locked the mutex" << std::endl;

  // Call wait()
  std::cout << "Reader thread sleeping/blocking..." << std::endl;
  // The condition variable will unlock the mutex, then block until the other
  // thread notifies the condition variable
  cond_var.wait(uniq_lck, [] { return condition; });

  // Condition variable wakes up the reader thread, the mutex is locked, and I
  // can use the data.
  std::cout << "Reader thread " << std::this_thread::get_id() << " wakes up"
            << std::endl;

  std::cout << "Data Received: \"" << shared_data << "\"" << std::endl;

  std::cout << "Reader thread is unlocking mutex" << std::endl;
}

void writer() {
  {
    // Lock the mutex
    std::cout << "Writer thread is locking mutex" << std::endl;

    std::lock_guard lck_gurd(mtx);

    std::this_thread::sleep_for(2s);

    // Modification
    std::cout << "Data Injection in writer thread..." << std::endl;
    shared_data = "Injected";

    condition = true;

    std::cout << "Writer thread is unlocking mutex" << std::endl;
  }
  // Notify the condition variable
  std::cout << "Writer thread sends notification" << std::endl;
  // cond_var.notify_one(); //For single thread
  // cond_var.notify_all(); // For multiple threads

  // Alternatively, call notify_one() in a loop to achieve the same as
  // notify_all()------Wake up one thread at a time.
  for (size_t i{}; i < 4; ++i) {
    cond_var.notify_one();
  }
}

int main(int argc, char const *argv[]) {
  // Initialize shared string
  shared_data = "Empty";

  // Display initial value
  std::cout << "Current data: \"" << shared_data << "\"" << std::endl;

  // Threads
  std::jthread write(writer);
  std::jthread read1(reader);
  std::this_thread::sleep_for(10ms);
  std::jthread read2(reader);
  std::this_thread::sleep_for(10ms);
  std::jthread read3(reader);
  std::this_thread::sleep_for(10ms);
  std::jthread read4(reader);
  std::this_thread::sleep_for(10ms);

  return 0;
}