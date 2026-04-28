module;

export module new_singleton;

import <iostream>;

using namespace std::literals;

export {
  class NewSingleton {

  public:
    NewSingleton() {
      std::cout << "New Singleton Object Created!" << std::endl;
    }
    NewSingleton(const NewSingleton &) = delete;
    NewSingleton(NewSingleton &&) = delete;
    NewSingleton &operator=(const NewSingleton &) = delete;
    NewSingleton &operator=(NewSingleton &&) = delete;
  };

  NewSingleton &getInstance() {
    static NewSingleton newSing;
    return newSing;
  }
}