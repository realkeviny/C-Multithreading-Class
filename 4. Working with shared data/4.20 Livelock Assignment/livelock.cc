import <iostream>;
import <thread>;
import <mutex>;

int x{0};
std::mutex mtx;

void func() {
    std::lock_guard lck_guard(mtx);
    while (x == 0) {
        x = 1 - x;
    }
    std::cout << "Current thread ID: " << std::this_thread::get_id() << ","
    << " x: " << x << std::endl;
}

int main()
{
    std::thread thr1{func};
    std::thread thr2{func};
	
	thr1.join();
	thr2.join();
}

