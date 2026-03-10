import <thread>;
import <iostream>;

int main(int argc, char const *argv[])
{

    std::thread thr([](){
        std::cout << "Hello,Lambda!" << std::endl;
    });
    thr.join();
    return 0;
}

