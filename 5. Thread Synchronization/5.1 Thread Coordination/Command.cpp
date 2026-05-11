import <string>;
import <mutex>;
import <iostream>;
import <thread>;
import <chrono>;

using namespace std::literals;

// Shared Variable.
// The fetcher thread will keep appending to it.
std::string shared_data;

// Two boolean flags to control threads
bool progress_update{};
bool completed{};

/**
 *  Why omitting the one for "progress_update"?
 *  Whenever this flag is modified/accessed, the data is also accessed as well.
 *  So, use 1 mutex for both, which is simpler and more efficient.
 *  (Or I can set a separate flag, or I can set up structure).
 */
// Mutexes to protect shared variables, one for data, and another one for
// "completed" flag
std::mutex mutex_for_shared_data;
std::mutex mutex_for_complete_status;

// Data Fetcher Thread
void fetch_data() {
  // Sleep and then append to the string
  for (size_t i{}; i < 5; ++i) {
    std::cout << "Fetcher thread is waiting for data..." << std::endl;
    std::this_thread::sleep_for(2s);

    // Lock the mutex before modifying the data
    std::lock_guard data_lck(mutex_for_shared_data);
    shared_data += "Block" + std::to_string(i + 1);
    std::cout << "Shared Data(Current): " << shared_data << std::endl;
    progress_update = true;
  }

  // When exiting the loop(which means the download is complete), tell the
  // progress bar thread to exit, and wake up the processor thread.
  std::lock_guard completed_lck(mutex_for_complete_status);
  completed = true;
}

// Progress Bar Thread
void progress_bar() {
  size_t data_length{};

  while (true) {
    std::cout << "Progress Bar thread is waiting for data..." << std::endl;

    // Check the mutex for the progress_update flag
    std::unique_lock data_lck(mutex_for_shared_data);
    // When the progress flag becomes true, it will exit the loop with a still
    // locked mutex.
    while (!progress_update) // Check the mutex for the progress update flag
    {
      data_lck.unlock();
      std::this_thread::sleep_for(10ms);
      data_lck.lock();
    }

    // Safe to access string data here
    // Made our own copy of the string data to
    // minimize the time for which we held the lock
    data_length = shared_data.length();

    // Set the flag back to false
    progress_update = false;
    data_lck.unlock();

    std::cout << "Received " << data_length << " bytes so far" << std::endl;

    // Check the completed flag, and see its changes
    std::lock_guard completed_lck(mutex_for_complete_status);
    if (completed) {
      std::cout << "Ending Progress Bar Thread..." << std::endl;
      break;
    }
  }
}

// Processor Thread
void data_processor() {
  std::cout << "Processor thread is waiting for data..." << std::endl;

  std::unique_lock completed_lck(mutex_for_complete_status);

  while (!completed) {
    completed_lck.unlock();
    std::this_thread::sleep_for(10ms);
    completed_lck.lock();
  }

  completed_lck.unlock();

  std::lock_guard data_lck(mutex_for_shared_data);
  std::cout << "Processing Data: " << shared_data << std::endl;

  // Processing...
}

int main(int argc, char const *argv[]) {
  std::jthread fetcher(fetch_data);
  std::jthread progress(progress_bar);
  std::jthread processor(data_processor);

  return 0;
}