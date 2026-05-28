import <future>;
import <iostream>;
import <chrono>;
import <thread>;

using namespace std::literals;

// TODO:Write a program which is similar to the second example in the lecture, but without using a packaged
// task. (For reference, the code used in the lecture is attached as a downloadable resource)
//  Your program will create two threads. The task function for the first thread will add together its arguments and
//  store the result in a promise object. The second thread will display the result of the addition performed by the
//  first thread.

/* Reference
int main(int argc, char *argv[])
{
    std::packaged_task<int(int, int)> ptask([](int a, int b) {
        std::this_thread::sleep_for(2s);
        return a + b;
    });

    std::future<int> ifut{ptask.get_future()};

    // In the same thread
    //  ptask(2, 9);

    // In a dedicated thread
    std::thread thr(std::move(ptask), 2, 9);

    std::cout << "Waiting for result\n";

    std::cout << "2 + 9 = " << ifut.get() << '\n';

    thr.join();
}
*/

void adder(std::promise<int> &presult, int x, int y)
{
    using namespace std::literals;

    int result{x + y};
    std::this_thread::sleep_for(2s);

    // Store the result in the shared state
    std::cout << "Promise sets shared state to " << result << '\n';

    presult.set_value(result);
}

void receiver(std::future<int> &fresult)
{
    std::cout << "Future calling get()..." << std::endl;
    int received{fresult.get()};
    std::cout << "Future returns from calling get()..." << std::endl;
    std::cout << "Value from get(): " << received << std::endl;
}

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <x> <y>\n";
        return 1;
    }
    std::promise<int> iprom;

    std::future<int> ifut{iprom.get_future()};

    std::jthread jadder(adder, std::ref(iprom), std::stoi(argv[1]), std::stoi(argv[2]));
    std::jthread jreceiver(receiver, std::ref(ifut));
}