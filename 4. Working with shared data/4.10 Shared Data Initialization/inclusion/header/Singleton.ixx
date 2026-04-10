module;

export module singleton;

import <iostream>;

export {
    class Singleton
    {
    public:
        Singleton();
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton &) = delete;
        Singleton(Singleton &&) = delete;
        Singleton &operator=(Singleton &&) = delete;
    };
    // Function to get the Singleton object)
    Singleton &get_Singleton();
}