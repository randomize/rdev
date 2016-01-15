#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

struct Foo
{
};

template<typename T>
class HashTable
{
public:

    void Insert(T* el)
    {
        _array.push_back(el);
    }

private:
    std::vector<T*> _array;
};


int main()
{

    HashTable<Foo> ints;

    ints.Insert(new Foo());

    return 0;
}
