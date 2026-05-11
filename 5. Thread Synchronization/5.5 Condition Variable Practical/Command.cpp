import <string>;
import <mutex>;
import <iostream>;
import <thread>;
import <chrono>;
import <condition_variable>;

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

std::condition_variable data_cv; // Notification about the download progress.
// Notifications about the download being completed.
std::condition_variable completed_cv;

// Data Fetcher Thread
void fetch_data() {
  // Sleep and then append to the string
  for (size_t i{}; i < 5; ++i) {
    std::cout << "Fetcher thread is waiting for data..." << std::endl;
    std::this_thread::sleep_for(2s);

    // Get the next block of data, then notify all the threads which are waiting
    // for information about the block of data
    std::unique_lock data_lck(mutex_for_shared_data);
    shared_data += "Block" + std::to_string(i + 1);
    std::cout << "Shared Data(Current): " << shared_data << std::endl;
    progress_update = true;
    data_lck.unlock();
    data_cv.notify_all();
  }

  // When exiting the loop(which means the download is complete), notify all the
  // threads which want to know if the download has completed
  std::lock_guard completed_lck(mutex_for_complete_status);
  completed = true;
  completed_cv.notify_all();
}

// Progress Bar Thread
void progress_bar() {
  size_t data_length{};

  while (true) {
    std::cout << "Progress Bar thread is waiting for data..." << std::endl;

    // Wait for the next block of data to arrive.
    std::unique_lock data_lck(mutex_for_shared_data);
    data_cv.wait(data_lck, [] { return progress_update; });

    // Update the progress
    data_length = shared_data.length();

    // Set the flag back to false to ensure that I get the next notification,
    // when the predicate is called
    progress_update = false;
    data_lck.unlock();

    std::cout << "Received " << data_length << " bytes so far" << std::endl;

    // Check the completed flag, and see its changes
    std::unique_lock completed_lck(mutex_for_complete_status);

    // The predicate will only return true if the fetching thread has notified
    // the completion condition variable.
    if (completed_cv.wait_for(completed_lck, 10ms, [] { return completed; })) {
      std::cout << "Ending Progress Bar Thread..." << std::endl;
      break;
    }

    // If: Blocking wait
    // completed_cv.wait(completed_lck, [] { return completed; });
    // std::cout << "Ending Progress Bar Thread..." << std::endl;
    // break;
  }
}

// Processor Thread
void data_processor() {
  std::cout << "Processor thread is waiting for data..." << std::endl;

  std::unique_lock completed_lck(mutex_for_complete_status);

  // Wait for the completion condition variable to be notified
  completed_cv.wait(completed_lck, [] { return completed; });

  // No longer needed lock
  completed_lck.unlock();

  // Wake up and start processing the data
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