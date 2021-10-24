#include <iostream>
#include <vector>
#include <cmath>

class MinHeap
{
public:
    MinHeap(int n);
    ~MinHeap() {}

    int leftIndex(int i) { return 2*i + 1; }
    int rightIndex(int i) {return 2*i + 2; }
    int parentIndex(int i) { return std::floor((i-1)/2); }

    void insert(int elem);
    void deleteKey(int idx);
    void traverse();
    void heapify(int idx);
    int extractMin();
    void decreaseKey(int idx, int newVal);

private:
    std::vector<int> _arr;
    int _size, _cap;
};

MinHeap::MinHeap(int n)
  : _cap(n), _size{0}
{
    _arr.resize(n);
}

void MinHeap::insert(int elem)
{
    if(_size == _cap)
        return;

    _arr[_size] = elem;
    _size++;

    int i = _size-1;
    int par = parentIndex(i);
    while (_arr[i] < _arr[par])
    {
        std::swap(_arr[i], _arr[par]);
        i = par;
        par = parentIndex(par);
    }    
}

void MinHeap::deleteKey(int idx)
{
    
}

void MinHeap::decreaseKey(int idx, int newVal)
{
    if(idx >= _size) return;

    _arr[idx] = newVal;
    while(idx != 0 && _arr[parentIndex(idx)] > _arr[idx])
    {
        std::swap(_arr[parentIndex(idx)], _arr[idx]);
        idx = parentIndex(idx);
    }
}

int MinHeap::extractMin()
{
    int min = _arr[0];
    _size--;
    std::swap(_arr[_size], _arr[0]);

    heapify(0);
    return min;
}

void MinHeap::heapify(int idx)
{
    int minIndex{idx};
    if(idx < _size && leftIndex(idx) < _size && _arr[leftIndex(idx)] < _arr[minIndex])
        minIndex = leftIndex(idx);
    if(idx < _size && rightIndex(idx) < _size && _arr[rightIndex(idx)] < _arr[minIndex])
        minIndex = rightIndex(idx);

    if(idx == minIndex)
        return;
    else
    {
        std::swap(_arr[idx], _arr[minIndex]);
        heapify(minIndex);
    }
}

void MinHeap::traverse()
{
    for(int i = 0; i < _size; i++)
        std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    MinHeap minHeap(4);
    minHeap.insert(6);
    minHeap.insert(8);
    minHeap.insert(12);
    minHeap.insert(4);

    minHeap.traverse();

    // minHeap.extractMin();
    minHeap.decreaseKey(3, 1);

    minHeap.traverse();

    return 0;
}
