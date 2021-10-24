#include <iostream>
#include <vector>
#include <algorithm>

double fractionalKnapsack(std::vector<std::pair<int, int>>& items, int knapsackWeight)
{
    // sort the items
    std::sort(items.begin(), items.end(), 
            [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            {
                return ((static_cast<float>(a.second)/a.first) < (static_cast<float>(b.second)/b.first));
            });

    double res{0};
    for(int i = 0; i < items.size(); i++)
    {
        if(knapsackWeight > items[i].second)
        {
            res += items[i].first;
            knapsackWeight -= items[i].second;
        }
        else
        {
            res += (static_cast<float>(knapsackWeight)/items[i].second) * items[i].first;
            break;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> itemsPriceAndWeight{{120, 30}, {100, 20}, {60, 10}};

    for(auto& item : itemsPriceAndWeight)
        std::cout << "(" << item.first << ", " << item.second << ")" << std::endl;

    std::cout << "--------------------------------" << std::endl;
    
    double res = fractionalKnapsack(itemsPriceAndWeight, 50);
    for(auto& item : itemsPriceAndWeight)
        std::cout << "(" << item.first << ", " << item.second << ")" << std::endl;

    std::cout << "Maximum price of items that can be put in the knapsack = " << res << std::endl;

    return 0;
}
