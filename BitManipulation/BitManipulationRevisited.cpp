#include <iostream>
#include <vector>

bool checkIfKthBitIsSet(int n, int k)
{
    return (((n >> (k - 1)) & 1) == 1);
}

int countSetBit(int n)
{
    int res{0};
    while(n != 0)
    {
        n = n & (n - 1);
        res++;
    }

    return res;
}

bool checkIfPowerOf2(int n)
{
    return ((n & (n-1)) == 0);
}

void printOddNumberInTheArray(const std::vector<int>& arr)
{
    int res{0};
    for(auto x : arr)
        res ^= x;
    
    std::cout << "Odd number in the array = " << res << std::endl;
}

int main(int argc, char const *argv[])
{
    int n, k;
    std::cout << "Pass n and k : ";
    std::cin >> n >> k;

    std::cout << "Check if " << k << "th bit of " << n << " set - " << (checkIfKthBitIsSet(n, k)? "true" : "false") << std::endl;
    std::cout << "Number of set bits in " << n << " = " << countSetBit(n) << std::endl;
    std::cout << "Is " << n << " power of 2? " << (checkIfPowerOf2(n)? "Yes" : "No") << std::endl;

    std::vector<int> arr{4, 3, 4, 4, 4, 5, 5};
    printOddNumberInTheArray(arr);

    return 0;
}
