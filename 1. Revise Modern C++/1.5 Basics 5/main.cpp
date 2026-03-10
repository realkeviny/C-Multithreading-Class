import <iostream>;
import <memory>;

struct Point
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    auto uptr{std::make_unique<Point>(Point{2, 4})};

    std::cout << uptr->x << ", " << uptr->y << '\n';
    return 0;
}
