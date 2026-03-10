import <thread>;
import <iostream>;
import <functional>;
import <string>;
// import math;

// class GreetFunc
// {
// public:
//     void operator()()
//     {
//         std::cout << "Hello Functor" << std::endl;
//     }
// };

// class Greeter
// {
// public:
//     void greeting()
//     {
//         std::cout << "Hello Member Function" << std::endl;
//     }
// };

// 4.Thread Function with pass by move
void print_str_func(std::string &&str)
{
    std::cout << "Received Message: " << str << std::endl;
}

class Printer
{
public:
    void operator()(std::string &&str)
    {
        std::cout << "Received Message: " << str << std::endl;
    }
};

int main(int argc, char const *argv[])
{

    /* 1.Hello thread program
    std::function<void()> printer;
    Greet greet;
    printer = greet;

    auto func = []()
    {
        std::cout << "Hello Lambda" << std::endl;
    };

    Greeter greeter;

    printer = greeter.greeting();
    // std::thread greetingThread(&Greeter::greeting, &greeter);
    // greetingThread.join();
    */

    /* 2. Thread Function with arguments
    Add_functor_edition afe;

    std::thread thrf(add_func_edition, -5, 5);
    std::thread thrfu(afe, -5, 5);
    std::thread thrl(add_lambda_edition, -5, 5);
    thrf.join();
    thrfu.join();
    thrl.join();
    */

    // 3. Thread Function with reference arguments
    // int x = 5;
    // Doubling_Functor df;
    // std::thread thrf(Doubling_func, std::ref(x));
    // std::thread thrfu(df, std::ref(x));
    // std::thread thrl(Doubling_lambda, std::ref(x));
    // thrf.join();
    // thrfu.join();
    // thrl.join();

    Printer printer;
    std::thread thrf(print_str_func, "Connected");
    std::thread thrfu(printer, "Connected");
    std::thread thrl([](std::string&& str){
        std::cout << "Received Message: " << str << std::endl;
    }, "Connected");
    thrf.join();
    thrfu.join();
    thrl.join();
    return 0;
}
