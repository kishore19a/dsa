#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int editDistance(std::string& s1, std::string& s2, int n, int m, std::vector<std::vector<int>>& memo)
{
    if(memo[n][m] == -1)
    {
        if(n == 0) memo[n][m] = m;
        else if(m == 0) memo[n][m] = n;
        else if(s1[n-1] == s2[m-1])
            memo[n][m] = editDistance(s1, s2, n-1, m-1, memo);
        else
            memo[n][m] = 1 + std::min({ editDistance(s1, s2, n-1, m-1, memo),
                                        editDistance(s1, s2, n-1, m, memo),
                                        editDistance(s1, s2, n, m-1, memo)
                                      });
    }

    return memo[n][m];
}

int editDistance(std::string& s1, std::string& s2)
{
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> memo(n+1, std::vector<int>(m+1, -1));

    return editDistance(s1, s2, n, m, memo);
}

int editDistanceDp(std::string& s1, std::string& s2)
{
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, -1));

    for(int i = 0; i <= n; i++)
        dp[i][0] = i;

    for(int j = 0; j <= m; j++)
        dp[0][j] = j;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + std::min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
        }
    }

    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    /* code */
    std::string s1{"SATURDAY"}, s2{"SUNDAY"};
    std::cout << "Minimum number of opertions required to make s1 to s2 using memoization = " << editDistance(s1, s2) << std::endl;
    std::cout << "Minimum number of opertions required to make s1 to s2 using tabulation = " << editDistanceDp(s1, s2) << std::endl;

    return 0;
}
