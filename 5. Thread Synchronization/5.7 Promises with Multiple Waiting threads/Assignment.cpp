import <iostream>;
import <string>;
import <thread>;
import <exception>;
import <future>;
import <mutex>;

std::mutex mtx;

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

void producer(std::promise<Order> &por) {
  Order example{1, "Eggs", 12};

  std::cout << "Current order: " << std::endl;
  std::cout << example << std::endl;

  por.set_value(example);
}

void consumer(std::shared_future<Order> &sfuor) {
  std::cout << "Thread " << std::this_thread::get_id() << " calling get()..."
            << std::endl;
  Order receipt{sfuor.get()};

  std::lock_guard<std::mutex> lck_guard(mtx);
  std::cout << "Thread " << std::this_thread::get_id()
            << " returns from calling get()" << std::endl;
  std::cout << "Thread " << std::this_thread::get_id() << " has receipt "
            << receipt << std::endl;
}

int main(int argc, char *argv[]) {
  std::promise<Order> opro;

  std::shared_future<Order> osfut{opro.get_future().share()};
  std::shared_future<Order> osfut2{osfut};

  std::jthread jt_producer(producer, std::ref(opro));
  std::jthread jt_consumer01(consumer, std::ref(osfut));
  std::jthread jt_consumer02(consumer, std::ref(osfut2));
}