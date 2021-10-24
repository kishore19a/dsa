// [10, 20, 30, 40, 50]
// [150, 60, 90, 30, 30, 40, 50, 10, 20]

#include <iostream>
#include <vector>

class SegmentTree
{
public:
    SegmentTree(std::vector<int>& arr);
    ~SegmentTree();

    void printSegmentTree();
    int getSum(int qs, int qe);
    void update(int index, int val);

private:
    std::vector<int> _arr, _segTree;
    int constructSegmentTree(int ss, int se, int si);
    int getSum(int qs, int qe, int ss, int se, int si);
    void update(int ss, int se, int si, int index, int diff); 
};

SegmentTree::SegmentTree(std::vector<int>& arr)
  : _arr(arr)
{
    _segTree.resize(4*_arr.size(), -1);
    constructSegmentTree(0, _arr.size()-1, 0);
}

SegmentTree::~SegmentTree()
{
}

int SegmentTree::constructSegmentTree(int ss, int se, int si)
{
    if(ss == se)
    {
        _segTree[si] = _arr[ss];
        return _segTree[si];
    }

    int mid{(ss + se) / 2};
    _segTree[si] = constructSegmentTree(ss, mid, 2*si + 1) + constructSegmentTree(mid+1, se, 2*si + 2);
}

int SegmentTree::getSum(int qs, int qe)
{
    if(qs < 0 ) qs = 0;
    if(qe >= _arr.size()) qe = _arr.size()-1;
    return getSum(qs, qe, 0, _arr.size()-1, 0);
}

int SegmentTree::getSum(int qs, int qe, int ss, int se, int si)
{
    if(ss > qe || se < qs) return 0;
    if(ss >= qs && se <= qe) return _segTree[si];

    int mid{(ss + se)/2};
    return (getSum(qs, qe, ss, mid, 2*si+1) + getSum(qs, qe, mid+1, se, 2*si+2));
}

void SegmentTree::update(int index, int val)
{
    _arr[index] = val;
    int diff{val - _arr[index]};
    update(0, _arr.size()-1, 0, index, diff);
}

void SegmentTree::update(int ss, int se, int si, int index, int diff)
{
    if(index < ss || index > se) return;

    _segTree[si] += diff;

    if(se > ss)
    {
        int mid{(ss + se)/2};
        update(ss, mid, 2*si+1, index, diff);
        update(mid+1, se, 2*si+2, index, diff);
    }
}

void SegmentTree::printSegmentTree()
{
    for(auto i : _segTree)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{10, 20, 30, 40, 50};
    SegmentTree segmentTree(arr);
    segmentTree.printSegmentTree();

    std::cout << "sum of elements from 0 to 2 = " << segmentTree.getSum(0, 2) << std::endl;
    std::cout << "sum of elements from 2 to 4 = " << segmentTree.getSum(2, 4) << std::endl;
    std::cout << "sum of elements from 0 to 8 = " << segmentTree.getSum(0, 8) << std::endl;

    segmentTree.update(2, 90);
    segmentTree.printSegmentTree();

    return 0;
}
