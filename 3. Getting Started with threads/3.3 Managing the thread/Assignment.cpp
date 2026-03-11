import <thread>;
import <iostream>;
import <exception>;

void greet()
{
    std::cout << "Hello, Thread" << std::endl;
}

// int main(int argc, char const *argv[])
// {
// TODO:Rewrite the "Hello, Thread!" program to call detach()
//     std::thread greetThr(greet);

//     greetThr.detach();
//     return 0;
// }

// TODO: Determine if this program work as expected
// int main()
// {
//     try
//     {
//         std::thread thr(greet);
//         throw std::exception();
//         thr.join();
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "Exception caught\n";
//     }
// }

// TODO: Rewrite the program so that it behaves correctly using a suitable try/catch block
/*
int main(int argc, char const *argv[])
{
    std::thread thr(greet);
    try
    {
        throw std::exception();
        thr.join();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught\n";
        thr.join();
    }
    return 0;
}
*/

// TODO: Rewrite the program so that it behaves correctly using an RAII class which wraps the std::thread object
// class thread_protector
// {
// private:
//     std::thread thr;

// public:
//     explicit thread_protector(std::thread &&thread_rref) : thr(std::move(thread_rref)) {}
//     ~thread_protector()
//     {
//         if (thr.joinable())
//         {
//             thr.join();
//         }
//     }

//     thread_protector(const std::thread &) = delete;
//     thread_protector &operator=(const std::thread &) = delete;
// };

// int main(int argc, char const *argv[])
// {
//     try
//     {
//         std::thread thr(greet);
//         thread_protector protector(std::move(thr));
//         throw std::exception();
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "Exception caught\n";
//     }
//     return 0;
// }

// TODO: Rewrite the program so that it behaves correctly using an std::jthread object
int main(int argc, char const *argv[])
{
    try
    {
        std::jthread thr(greet);
        throw std::exception();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught\n";
    }
}
