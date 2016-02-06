#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

// Declare Foo and Bar structs
struct Foo
{
    int x;
};

struct Bar
{
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& stream, const Foo& obj)
{
    cout << "(x: " << obj.x << ")" << endl;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Bar& obj)
{
    cout << "(x: " << obj.x << ", y: " << obj.y << ")" << endl;
    return stream;
}

template <typename T>
void print_me(T obj)
{
    cout << "Value: {}" << obj << endl;
}

int main(int argc, char* argv[])
{
    auto foo = Foo{7};
    auto bar = Bar{5, 10};

    print_me(foo);  // one
    print_me(bar);  // tow

    return 0;
}
