module;

module singleton;

import <iostream>;

Singleton::Singleton()
{
    std::cout << "Initializing Singleton" << std::endl;
}

Singleton &get_Singleton()
{
    static Singleton single;
    return single;
}