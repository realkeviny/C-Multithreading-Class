import <iostream>;
import <thread>;
import <chrono>;
import <future>;

/*
void producer(std::promise<int> &px) {
  using namespace std::literals;

  int x{37};
  std::this_thread::sleep_for(2s);

  // Store the result in the shared state
  std::cout << "Promise sets shared state to " << x << '\n';
  px.set_value(x);
}

void consumer(std::future<int> &fx) {
  std::cout << "Future calling get()..." << std::endl;
  int x{fx.get()};
  std::cout << "Future returns from calling get()..." << std::endl;
  std::cout << "Value from get(): " << x << std::endl;
}
*/

// With exceptions
/*
void producer(std::promise<int> &px) {

  try {
    using namespace std::literals;

    int x{37};
    std::this_thread::sleep_for(2s);

    // Code that may throw
    if (false) {
      throw std::out_of_range("Actually not");
    }

    // Store the result in the shared state -- If no exception
    std::cout << "Promise sets shared state to " << x << '\n';
    px.set_value(x);
  } catch (...) {
    // Re-throw exception - store it in the shared state
    px.set_exception(std::current_exception());
  }
}
*/

// Using make_exception_ptr
void producer(std::promise<int> &px) {

  using namespace std::literals;

  int x{37};
  std::this_thread::sleep_for(2s);

  if (true) {
    px.set_exception(
        std::make_exception_ptr(std::out_of_range("Actually not")));
    return;
  }
  // Store the result in the shared state -- If no exception
  std::cout << "Promise sets shared state to " << x << '\n';
  px.set_value(x);
}

void consumer(std::future<int> &fx) {
  std::cout << "Future calling get()..." << std::endl;
  try {
    int x{fx.get()};
    std::cout << "Future returns from calling get()..." << std::endl;
    std::cout << "Value from get(): " << x << std::endl;
  } catch (std::exception &ex) {
    std::cout << "Exception caught: " << ex.what() << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  std::promise<int> iprom;

  std::future<int> ifut{iprom.get_future()};

  std::jthread jt_producer(producer, std::ref(iprom));
  std::jthread jt_consumer(consumer, std::ref(ifut));

  return 0;
}