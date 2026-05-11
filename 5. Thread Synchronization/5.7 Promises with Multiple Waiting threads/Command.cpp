import <iostream>;
import <thread>;
import <chrono>;
import <future>;
import <mutex>;

std::mutex mtx;
void producer(std::promise<int> &px) {
  using namespace std::literals;

  int x{37};
  std::this_thread::sleep_for(2s);

  // Store the result in the shared state
  std::cout << "Promise sets shared state to " << x << '\n';
  px.set_value(x);
}

void consumer(std::shared_future<int> &fx) {
  std::cout << "Thread " << std::this_thread::get_id() << " calling get()..."
            << std::endl;
  int x{fx.get()};
  std::lock_guard<std::mutex> lck_guard(mtx);
  std::cout << "Thread " << std::this_thread::get_id()
            << " returns from calling get()" << std::endl;
  std::cout << "Thread " << std::this_thread::get_id() << " has answer " << x
            << std::endl;
}

int main(int argc, char const *argv[]) {
  std::promise<int> iprom;

  std::shared_future<int> ifut{iprom.get_future()};
  std::shared_future<int> ifut2{ifut};

  std::jthread jt_producer(producer, std::ref(iprom));
  std::jthread jt_consumer(consumer, std::ref(ifut));
  std::jthread jt_consumer2(consumer, std::ref(ifut2));

  return 0;
}