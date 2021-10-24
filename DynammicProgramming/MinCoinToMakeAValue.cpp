#include <iostream>
#include <vector>

// int getMax(std::vector<int> coins, int n, int val)
// {
//     if(n == 0) return 0;
//     if(val == 0) return 1;

//     int res = getMax(coins, n-1, val);
//     if(coins[n-1] <= val)
//         res = res + getMax(coins, n, val-coins[n-1]);

//     return res;
// }

int getMaxAn(std::vector<int> coins, int n, int val)
{
    if(n == 0) return 0;
    if(val == 0) return 0;

    
    if(coins[n-1] <= val)
        return std::max(1+getMaxAn(coins, n, val-coins[n-1]), getMaxAn(coins, n-1, val));
    else
        return getMaxAn(coins, n-1, val);
}

int main(int argc, char const *argv[])
{
    std::vector<int> coins({2, 5, 3, 6});
    int val{10};
    int maxCoins = getMaxAn(coins, coins.size(), val);

    std::cout << "Maximum number of coins required to get value - " << val << " = " << maxCoins << std::endl;
    return 0;
}
