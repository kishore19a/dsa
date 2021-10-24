#include <iostream>
#include <vector>

// Naive Partition method - O(n) in time and auxillary space.
// Stable, but need to make 4 traversal of the array
int naivePartition(std::vector<int>& arr, int l, int h, int p)
{
    std::vector<int> part;

    for(int i = l; i <= h; i++)
        if(arr[i] < arr[p])
            part.push_back(arr[i]);

    for(int i = l; i <= h; i++)
        if(arr[i] == arr[p])
            part.push_back(arr[i]);

    int index = l + part.size() - 1;

    for(int i = l; i <= h; i++)
        if(arr[i] > arr[p])
            part.push_back(arr[i]);

    for(int i = l; i <= h; i++)
        arr[i] = part[i-l];

    return index;
}

int lomutoPartition(std::vector<int>& arr, int l, int h)
{   
    int p{h}, j{l};
    for(int i = l; i < h; i++)
    {
        if(arr[i] < arr[p])
        {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
    std::swap(arr[j], arr[p]);
    
    return j;
}

int hoarePartition(std::vector<int>& arr, int l, int h)
{
    int pivotElem = arr[l];
    int i{l-1}, j{h+1};

    while(true)
    {
        do
        {
            i++;
        } while (arr[i] <= pivotElem);

        do
        {
            j--;
        } while (arr[j] > pivotElem);

        std::cout << "i = " << i << ", j = " << j << std::endl;
        
        if(i >= j) return j;
        std::swap(arr[i], arr[j]);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{5, 3, 8, 4, 2, 7, 1, 10};
    // int pIndex = naivePartition(arr, 0, 4, 0);
    // int pIndex = lomutoPartition(arr, 0, 6);
    int pIndex = hoarePartition(arr, 0, arr.size()-1);
    std::cout << "After partition: ";
    for(auto x : arr)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "Index of pivot = " << pIndex << std::endl;
    
    return 0;
}
