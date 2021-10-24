#include <iostream>
#include <vector>
#include <algorithm>

int maxSizeOfIsland(std::vector<std::vector<int>>& grid, int i, int j, int m, int n)
{
    if(i < 0 || i >= m) return 0;
    if(j < 0 || j >= n) return 0;

    if(grid[j][i] == 1) return (1 + std::max({
        maxSizeOfIsland(grid, i+1, j, m, n),
        maxSizeOfIsland(grid, i, j+1, m, n)
    }));
    else
        return (std::max({
        maxSizeOfIsland(grid, i+1, j, m, n),
        maxSizeOfIsland(grid, i, j+1, m, n)
    }));  
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> grid({{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}});
    std::vector<std::vector<bool>> visited(4, std::vector<bool>(4, false));

    std::cout << maxSizeOfIsland(grid, 0, 0, 4, 4) << std::endl;
    return 0;
}
