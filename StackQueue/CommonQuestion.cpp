#include <iostream>
#include <stack>
#include <queue>
#include <vector>

class StackFromArray
{
public:
    StackFromArray(int cap);
    ~StackFromArray() {}

    void push(int n);
    int top();
    void pop();
    int size();

private:
    std::vector<int> arr;
    int _cap{0};
    int _top{-1};
};

StackFromArray::StackFromArray(int cap)
  : _cap(cap)
{
    arr.resize(cap);
}

void StackFromArray::push(int n)
{
    if(_top < cap)
    {
        arr[++top] = n;
    }
}

int StackFromArray::top()
{
    return arr[_top];
}

void StackFromArray::push(int n)
{
    if(_top >= 0)
    {
        _top--;
    }
}

int StackFromArray::size()
{
    return (_top + 1);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
