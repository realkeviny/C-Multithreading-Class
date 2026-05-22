#include <iostream>
#include <iterator>
#include <list>
#include <thread>
#include <vector>

template <typename T>
class LockFreeQueue;

template <typename T>
void print_collection(LockFreeQueue<T>);

template <typename T>
class LockFreeQueue
{
    friend void print_collection<T>(LockFreeQueue<T> param_queue);

private:
    std::list<T> list;
    typename std::list<T>::iterator iHead, iTail;

public:
    LockFreeQueue()
    {
        list.emplace_back(T()); // Put a dummy value in
        iHead = list.begin();
        iTail = list.end();
    }
    void Producer(const T &val);
    bool Consumer(T &val);
};

template <typename T>
void LockFreeQueue<T>::Producer(const T &val)
{
    list.push_back(val);
    iTail = list.end();
    list.erase(list.begin(), iHead);
}

template <typename T>
bool LockFreeQueue<T>::Consumer(T &val)
{
    // Head to the first element
    auto iFirst{iHead};
    ++iFirst;

    if (iFirst != iTail)
    {
        // Update iHead
        iHead = iFirst;
        // Fetch the 1st element
        val = *iHead;
        return true;
    }
    // Not found/No element to fetch
    return false;
}

template <typename T>
void print_collection(LockFreeQueue<T> param)
{
    auto iFirst{param.iHead};
    ++iFirst;

    for (auto it = iFirst; it != param.iTail; ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    LockFreeQueue<int> ilfq;
    std::vector<std::thread> tasks;
    int j{1};

    for (int i{}; i < 10; ++i)
    {
        std::thread producing(&LockFreeQueue<int>::Producer, &ilfq, std::ref(i));
        tasks.emplace_back(std::move(producing));
        std::thread consuming(&LockFreeQueue<int>::Consumer, &ilfq, std::ref(j));
        tasks.emplace_back(std::move(consuming));
    }

    for (auto &thr : tasks)
    {
        thr.join();
    }

    print_collection(ilfq);
}