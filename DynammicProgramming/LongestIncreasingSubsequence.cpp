#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> arr{3, 4, 2, 8, 10, 5, 1};
    std::vector<int> lis(arr.size(), 1);

    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
                lis[i] = std::max(lis[i], 1+lis[j]);
        }
    }

    int maxLis = *std::max_element(lis.begin(), lis.end());
    std::cout << "LIS = " << maxLis << std::endl;

    return 0;
}
