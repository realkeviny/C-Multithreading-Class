import <mutex>;
import <vector>;
import <iostream>;

template <typename T>
class InternallySynchronizedVector
{
private:
    std::mutex manage_mutex;
    std::vector<T> vec;

public:
    void PushBack(const T &val)
    {
        manage_mutex.lock();
        vec.push_back(val);
        manage_mutex.unlock();
    }

    void print_collection()
    {
        manage_mutex.lock();
        std::ranges::copy(ivec, std::ostream_iterator<T>(std::cout, " "));
        manage_mutex.unlock();
    }
};

int main(int argc, char const *argv[])
{
    InternallySynchronizedVector<int> safe_vec;

    std::thread t1([&]()
                   {
        for (int i = 1; i <= 3; ++i) safe_vec.PushBack(i); });

    std::thread t2([&]()
                   {
        for (int i = 1; i <= 3; ++i) safe_vec.PushBack(i * 10); });

    t1.join();
    t2.join();
    std::cout << "Collection contents: ";
    safe_vec.print_collection();
    std::cout << std::endl;

    return 0;
}