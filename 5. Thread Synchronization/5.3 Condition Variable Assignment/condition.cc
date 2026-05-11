#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::literals;

// TODO:Rewrite the first condition variable example from the video to use a
// boolean flag instead of a condition variable. Your program must not contain
// any data race, deadlock or livelock conditions.

// Global variables
mutex mut;
bool modified{};
string sdata{"Empty"};

// Waiting thread
void reader() {
  unique_lock<std::mutex> guard(mut); // Acquire lock
  while (!modified) {
    guard.unlock();
    std::this_thread::sleep_for(100ms);
    guard.lock();
  }
  cout << "Data is " << sdata << endl; // Wake up and use the new value
}

// Modyifing thread
void writer() {
  cout << "Writing data..." << endl;
  lock_guard<std::mutex> lg(mut); // Acquire lock
  if (!modified) {
    std::this_thread::sleep_for(2s); // Pretend to be busy...
    sdata = "Populated";             // Modify the data
    modified = true;
  }
}

int main() {
  cout << "Data is " << sdata << endl;
  thread read{reader};
  thread write{writer};
  /*
  // If the writer thread finishes before the reader thread starts, the
  notification is lost thread write{writer}; std::this_thread::sleep_for(500ms);
  thread read{reader};
  */
  write.join();
  read.join();
}