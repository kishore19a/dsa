#include <iostream>
#include <cmath>

class MinHeap
{
public:
    MinHeap(int cap);
    ~MinHeap();

    int left(int i) { return (2*i+1); }
    int right(int i) { return (2*i+2); }
    int parent(int i) { return std::floor((i-1)/2); }

    void insert(int key);
    void printHeap();

private:
    int* _arr;
    int _size;
    int _cap;

    void heapify(int keyPos);
};

MinHeap::MinHeap(int cap)
 : _cap(cap), _size{0}
{
    _arr = new int[cap];
}

MinHeap::~MinHeap()
{
    delete[] _arr;
}

void MinHeap::heapify(int keyPos)
{
    if(keyPos <= 0) return;

    if(_arr[parent(keyPos)] > _arr[keyPos])
    {
        std::swap(_arr[parent(keyPos)], _arr[keyPos]);
        heapify(parent(keyPos));
    }
}

void MinHeap::printHeap()
{
    for(int i = 0; i < _size; i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

void MinHeap::insert(int key)
{
    if(_size >= _cap)
    {
        std::cout << "Max size of heap reached" << std::endl;
        return;
    }

    _arr[_size] = key;
    heapify(_size);
    _size++;
}

int main(int argc, char const *argv[])
{
    MinHeap minHeap(10);

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(40);
    minHeap.insert(50);
    minHeap.insert(100);
    minHeap.insert(25);
    minHeap.insert(45);
    minHeap.insert(12);
    minHeap.insert(5);

    minHeap.printHeap();

    return 0;
}

