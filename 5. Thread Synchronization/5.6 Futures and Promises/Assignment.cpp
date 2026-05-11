import <iostream>;
import <string>;
import <thread>;
import <exception>;
import <future>;

class Order {
  friend std::ostream &operator<<(std::ostream &os, const Order &order);

public:
  Order(int id, std::string item, int quantity)
      : id(id), item(std::move(item)), quantity(quantity) {}

private:
  int id;
  std::string item;
  int quantity;
};

inline std::ostream &operator<<(std::ostream &os, const Order &order) {
  os << "ID: " << order.id << " ,Item Name:" << order.item
     << " ,Quantity:" << order.quantity << std::endl;
  return os;
}

// TODO: Write a multi-threaded program which uses the producer-consumer model
// with std :: promise and std :: future
/*
void producer(std::promise<Order> &por) {
  Order example{1, "Eggs", 12};

  std::cout << "Current order: " << std::endl;
  std::cout << example << std::endl;

  por.set_value(example);
}

void consumer(std::future<Order> &fuor) {
  std::cout << "Future calling get()..." << std::endl;
  Order receipt{fuor.get()};

  std::cout << "Future returns from calling get()..." << std::endl;
  std::cout << "Value from get(): " << std::endl;
  std::cout << receipt << std::endl;
}
*/

// TODO: Write a multi-threaded program which uses the producer-consumer model
// with std :: promise and std :: future.The producer thread of this program
// throws an exception which is handled in the consumer thread
void producer(std::promise<Order> &por) {
  Order example{1, "Eggs", 12};

  std::cout << "Current order: " << std::endl;
  std::cout << example << std::endl;

  if (true) {
    por.set_exception(
        std::make_exception_ptr(std::runtime_error("System Maintenance")));
    return;
  }

  por.set_value(example);
}

void consumer(std::future<Order> &fuor) {
  std::cout << "Future calling get()..." << std::endl;
  try {
    Order receipt{fuor.get()};
    std::cout << "Future returns from calling get()..." << std::endl;
    std::cout << "Value from get(): " << std::endl;
    std::cout << receipt << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::promise<Order> opro;

  std::future<Order> ofut{opro.get_future()};

  std::jthread jt_producer(producer, std::ref(opro));
  std::jthread jt_consumer(consumer, std::ref(ofut));
}