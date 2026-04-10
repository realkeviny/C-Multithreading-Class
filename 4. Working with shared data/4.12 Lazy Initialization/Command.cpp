import <thread>;
import <iostream>;
import <mutex>;

// Single-Threaded Lazy Initialization(Old-School)
/*
class Test
{
public:
    void func() {}
};

Test *ptest = nullptr;
std::mutex mut;

void process()
{
    std::unique_lock<std::mutex> uniq_lck(mut);
    if (!ptest)
    {
        ptest = new Test;
    }
    uniq_lck.unlock();
    ptest->func();
}
*/

// Multi-Threaded Lazy Initialization(std::call_once)
class Test
{
public:
    Test()
    {
        std::cout << "Calling Test Constructor..." << std::endl;
    }
    void func() {}
};

Test *ptest = nullptr;
std::once_flag ptestFlag;

void process()
{
    std::call_once(ptestFlag, []()
                   { ptest = new Test; });
    ptest->func();
}

int main(int argc, char const *argv[])
{
    std::jthread jt1(process);
    std::jthread jt2(process);
    return 0;
}
