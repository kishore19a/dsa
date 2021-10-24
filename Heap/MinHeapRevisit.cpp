#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>

class MinHeap
{
private:
    std::vector<int> arr;
    int size{0}, capacity;

public:
    MinHeap(int cap) : capacity(cap)
    {
        arr.resize(cap);
    }
    ~MinHeap(){}

    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }
    int parent(int i) { return std::floor((i-1)/2); }
    
    void insert(int n);
    void traverseHeap();
    void minHeapify(int i);
    void buildHeap(std::vector<int>& vec);
    int extractMin();
};

void MinHeap::insert(int n)
{
    if(size >= capacity) return;
    arr[size] = n;

    int i{size};
    while(i != 0 && arr[i] < arr[parent(i)])
    {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }

    size++;
}

void MinHeap::traverseHeap()
{
    for(auto x : arr)
        std::cout << x << " ";
    std::cout << std::endl;
}

void MinHeap::minHeapify(int i)
{
    int smallestIndex{i};
    if(i < size && left(i) < size && arr[smallestIndex] > arr[left(i)])
        smallestIndex = left(i);
    if(i < size && right(i) < size && arr[smallestIndex] > arr[right(i)])
        smallestIndex = right(i);

    if(smallestIndex != i)
    {
        std::swap(arr[i], arr[smallestIndex]);
        minHeapify(smallestIndex);
    }
    else return;
}

void MinHeap::buildHeap(std::vector<int>& vec)
{
}

int MinHeap::extractMin()
{
    int min =  arr[0];
    arr[0] = arr[size-1];
    size--;

    minHeapify(0);
    return min;
}

int main(int argc, char const *argv[])
{
    int n{10};
    MinHeap minHeap{n};

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

    minHeap.traverseHeap();

    int min = minHeap.extractMin();
    std::cout << "Min element = " << min << std::endl;

    return 0;
}
