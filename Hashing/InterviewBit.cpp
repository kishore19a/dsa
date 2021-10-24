#include <iostream>
#include <deque>
#include <vector>
#include <unordered_set>
#include <unordered_map>

bool hasArrayTwoCandidates(int arr[], int n, int x) {
    std::unordered_set<int> elems;
    for (int i = 0; i < n; i++)
    {
        int b = x - arr[i];
        if(elems.find(b) != elems.end())
            return true;
        else
            elems.insert(arr[i]);
    }
    
    return false;
}

int colorful(int A) {
    std::deque<int> elems;
    int temp{A};

    while(temp != 0)
    {
        int rem = temp % 10;
        elems.push_front(rem);
        temp /= 10;
    }

    int l{0}, r{0};
    std::unordered_set<int> prods;

    while(l <= r && l < elems.size())
    {
        while(r < elems.size())
        {
            int pr{1};
            for(int i = l; i <= r; i++)
                pr *= elems[i];

            if(prods.find(pr) != prods.end())
                return 0;
            else
                prods.insert(pr);

            r++;
        }
        l++;
        r=l;
    }

    return 1;
}

std::vector<int> lszero(std::vector<int> &A) {
    std::vector<int> res;
    std::unordered_map<int, int> lczeroMap;
    int sum{0}, len{-1}, startIndex{-1}, endIndex{-1};

    for(int i = 0; i < A.size(); i++)
    {
        sum += A[i];

        std::cout << sum << std::endl;

        if(sum == 0)
        {
            int currLen = i + 1;
            if(currLen > len)
            {
                len = currLen;
                startIndex = 0;
                endIndex = i;
            }
        }
        else
        {
            if(lczeroMap.find(sum) != lczeroMap.end())
            {
                int currLen = i - lczeroMap[sum];
                if(currLen > len)
                {
                    len = currLen;
                    startIndex = lczeroMap[sum] + 1;
                    endIndex = i;
                }
            }
            else
            {
                lczeroMap[sum] = i;
            }
        }
    }

    if(startIndex != -1 && endIndex != -1 && startIndex <= endIndex)
    {
        for(int i = startIndex; i <= endIndex; i++)
        {
            res.push_back(A[i]);
        }
    }

    return res;
}


int main(int argc, char const *argv[])
{
    // int arr[6] = {1, 4, 45, 6, 10, 8};
    // if(hasArrayTwoCandidates(arr, 6, 7))
    //     std::cout << "Yes" << std::endl;
    // else
    //     std::cout << "No" << std::endl;

    // int A{123};
    // if(colorful(A))
    //     std::cout << "Yes" << std::endl;
    // else
    //     std::cout << "No" << std::endl;

    std::vector<int> A{1, 2, -2, 4, -4};
    std::vector<int> out(lszero(A));

    for(auto x : out)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
