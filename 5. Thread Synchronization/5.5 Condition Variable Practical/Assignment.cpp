import <chrono>;
import <iostream>;
import <mutex>;
import <string>;
import <thread>;
import <vector>;
import <condition_variable>;

using namespace std::literals;

struct DownloadTask {
  std::string url;
  int total_chunks;

  std::mutex data_mtx;
  std::vector<uint8_t> data; // Downloadable Content
  bool data_read{};
  std::condition_variable data_read_cv;

  std::mutex done_mtx;
  bool fetch_done{};
  std::condition_variable fetch_done_cv;

  explicit DownloadTask(std::string u, int n)
      : url(std::move(u)), total_chunks(n) {}
};

void fetcher(DownloadTask &task) {
  for (size_t i{}; i < task.total_chunks; ++i) {
    std::cout << "Fetcher thread is waiting for data..." << std::endl;
    std::this_thread::sleep_for(2s);

    std::vector<uint8_t> chunk = {0x48, 0x65, 0x6c, 0x6c, 0x6f};
    // Lock the mutex before modifying the data
    std::lock_guard data_lck(task.data_mtx);
    task.data.insert(task.data.end(), chunk.cbegin(), chunk.cend());
    std::cout << "Current data: ";
    for (auto byte : task.data)
      std::cout << std::hex << static_cast<int>(byte) << " ";
    std::cout << std::dec << "\n";
    task.data_read = true;
    task.data_read_cv.notify_all();
  }

  // When exiting the loop(which means the download is complete), tell the
  // progress bar thread to exit, and wake up the processor thread.
  std::lock_guard completed_lck(task.done_mtx);
  task.fetch_done = true;
  task.fetch_done_cv.notify_all();
}

void progress_bar(DownloadTask &task) {
  size_t data_length{};
  while (true) {

    std::cout << "Progress Bar thread is waiting for data..." << std::endl;
    std::unique_lock data_lck(task.data_mtx);

    task.data_read_cv.wait(data_lck, [&task] { return task.data_read; });
    data_length = task.data.size();

    // Set the flag back to false
    task.data_read = false;
    data_lck.unlock();

    std::cout << "Received " << data_length << " chunks so far" << std::endl;

    // Check the completed flag, and see its changes
    std::unique_lock completed_lck(task.done_mtx);
    if (task.fetch_done_cv.wait_for(completed_lck, 10ms,
                                    [&task] { return task.fetch_done; })) {
      std::cout << "Ending Progress Bar Thread..." << std::endl;
      break;
    }
  }
}

void processor(DownloadTask &task) {
  std::cout << "Processor thread is waiting for data..." << std::endl;

  std::unique_lock completed_lck(task.done_mtx);
  task.fetch_done_cv.wait(completed_lck, [&task] { return task.fetch_done; });

  completed_lck.unlock();
  std::lock_guard data_lck(task.data_mtx);
  std::string as_string(task.data.cbegin(), task.data.cend());
  std::cout << "Processed data: " << as_string << "\n";

  // Pretend to be Processing....
}

int main(int argc, char *argv[]) {
  DownloadTask task("https://ferban.org/servercode.bin", 5);

  std::jthread t1(fetcher, std::ref(task));
  std::jthread t2(progress_bar, std::ref(task));
  std::jthread t3(processor, std::ref(task));

  std::cout << "Done. Processed " << task.data.size() << " bytes.\n";
  return 0;
}