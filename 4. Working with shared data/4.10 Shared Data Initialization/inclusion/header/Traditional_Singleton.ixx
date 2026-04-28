module;

export module traditional_singleton;

import <iostream>;
import <chrono>;
import <thread>;

using namespace std::literals;

export {
  class TraditionalSingleton {
  private:
    inline static TraditionalSingleton *tradsing{};

    TraditionalSingleton() {
      std::cout << "Traditional Singleton Object Created!" << std::endl;
    }

  public:
    static TraditionalSingleton *getInstance() {
      if (tradsing == nullptr) {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        tradsing = new TraditionalSingleton;
      }
      return tradsing;
    }

    TraditionalSingleton(const TraditionalSingleton &) = delete;
    TraditionalSingleton(TraditionalSingleton &&) = delete;
    TraditionalSingleton &operator=(const TraditionalSingleton &) = delete;
    TraditionalSingleton &operator=(TraditionalSingleton &&) = delete;
  };
}