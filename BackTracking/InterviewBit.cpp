#include <iostream>
#include <vector>

void printAllPermutation(std::vector<int>& arr, int l, int r)
{
    if(l == r)
    {
        for(auto x : arr)
            std::cout << x << " ";
        std::cout << std::endl;
    }
    else
    {
        for(int i = l; i < r; i++)
        {
            std::swap(arr[i], arr[l]);
            printAllPermutation(arr, l+1, r);
            std::swap(arr[i], arr[l]);
        }
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{1, 2, 3};
    printAllPermutation(arr, 0, 3);
    return 0;
}
