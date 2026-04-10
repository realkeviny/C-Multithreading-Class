import <thread>;
import <iostream>;
import <mutex>;
import <chrono>;
import <vector>;
import <algorithm>;

using namespace std::literals;

class LockedVector
{
private:
    std::vector<int> ivec;
    std::mutex mutex_for_manage;

public:
    void push_back(const int &num)
    {
        mutex_for_manage.lock();
        ivec.push_back(num);
        mutex_for_manage.unlock();
    }

    void print()
    {
        mutex_for_manage.lock();
        std::ranges::copy(ivec, std::ostream_iterator<int>(std::cout, " "));
        mutex_for_manage.unlock();
    }
};

void func(LockedVector &lockedVec)
{
    for (size_t i = 0; i < 5; ++i)
    {
        lockedVec.push_back(i);
        std::this_thread::sleep_for(50ms);
        lockedVec.print();
    }
}

int main(int argc, char const *argv[])
{
    LockedVector lvec;
    std::jthread thr1(func, std::ref(lvec));
    std::jthread thr2(func, std::ref(lvec));
    std::jthread thr3(func, std::ref(lvec));
    return 0;
}
