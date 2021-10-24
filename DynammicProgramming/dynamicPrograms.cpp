#include <iostream>
#include <string>
#include <stack>

int LIS(std::string& s1, int n, std::string& s2, int m, std::string& comStr)
{
    if(n == 0 || m == 0)
        return 0;

    if(s1[n-1] == s2[m-1])
    {
        comStr = s1[n-1] + comStr;
        return 1 + LIS(s1, n-1, s2, m-1, comStr);
    }
    else
        return std::max(LIS(s1, n-1, s2, m, comStr), LIS(s1, n, s2, m-1, comStr));
}

int main(int argc, char const *argv[])
{
    std::string s1{"ABCDGH"}, s2{"AEDFHR"}, comStr{};

    int len = LIS(s1, s1.size(), s2, s2.size(), comStr);
    std::cout << "Longest increasing subsequence = " << comStr << std::endl;
    std::cout << "Length of longest increasing subsequence = " << len << std::endl;

    return 0;
}
