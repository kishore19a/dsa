#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findInBitonicSeq(std::vector<int>& A, int B)
{
    int l{0}, h{A.size()-1};
    while (l <= h)
    {
        int mid = (l+h)/2;

        // key found
        if(A[mid] == B)
            return mid;
        else if (A[mid] < B)
        {
            if(mid > 0)
            {
                // increasing sequence, so all elements to the left will also be smaller
                // so the number must be on the right
                if(A[mid] > A[mid-1])
                    l = mid+1;
                // decreasing sequence, so all elements to the right will also be smaller
                // so the number must be on the left
                else
                    h = mid-1;
            }
            // B is smaller than the first element
            else
                h = mid-1;            
        }
        else
        {
            if(mid > 0)
            {
                // increasing sequence, so all elements to the right will also be larger
                // so the number must be on the left
                if(A[mid] > A[mid-1])
                    h = mid-1;
                // decreasing sequence, so all elements to the left will also be larger
                // so the number must be on the right
                else
                    l = mid+1;
            }
            // B is larger than the first element
            else
                l = mid+1;
        }
    }
    
    return -1;
}

int countSmallOrEqualElements(std::vector<int>& A, int B)
{
    int l{0}, h{A.size()-1}, res{0};
    while (l <= h)
    {
        int mid = (l+h)/2;
        if(A[mid] == B)
        {
            while(A[mid+1] == A[mid])
                mid++;
            res = mid+1;
            return res;
        }
        else if (A[mid] > B)
            h = mid-1;
        else
        {
            l = mid+1;
            res = l;
        }
    }
    
    return res;
}

void setMatrixZero(std::vector<std::vector<int>>& matrix)
{
    if(matrix.size() == 0) return;

    int numRows = matrix.size();
    int numCols = matrix[0].size();

    std::vector<int> colVec(numCols, -1);
    std::vector<int> rowVec(numRows, -1);

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            
        }
    }
}

vector<vector<long int> > threeSum(vector<long int> &A) {
    std::vector<std::vector<long int>> res;
    if(A.size() <= 2)
        return res;

    std::sort(A.begin(), A.end());

    for(int i = 0; i < A.size()-2; i++)
    {
        long int req = -1 * A[i];
        int j = i+1;
        int k = A.size()-1;

        while(j < k && k < A.size())
        {
            int sum = A[j] + A[k];
            std::cout << sum << " " << req << std::endl;
            if(sum == req)
            {
                res.push_back({A[i], A[j], A[k]});
                while(A[j+1] == A[j]) j++; 
                while(A[k-1] == A[k]) k--;
                j++; k--;
            }
            else if(sum < req)
                j++;
            else
                k--;
        }

        while(A[i+1] == A[i])
            i++;
    }

    return res;
}

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i{0}, j{0}, k{0};
    std::vector<int> C(A.size() + B.size());

    while(i < A.size() && j < B.size())
    {
        if(A[i] <= B[j])
        {
            C[k] = A[i]; i++; k++;
        }
        else
        {
            C[k] = B[j]; j++; k++;
        }
    }

    while(i < A.size())
    {
        C[k] = A[i]; i++; k++;
    }

    while(j < B.size())
    {
        C[k] = B[j]; j++; k++;
    }

    A.clear();
    for(auto x : C)
        A.push_back(x);
}


int main(int argc, char const *argv[])
{
    // std::vector<int> arr{1, 2, 2, 2, 2, 5, 7, 9};
    // int key{2};
    // int keyFoundAt = findInBitonicSeq(arr, key);

    // if(keyFoundAt != -1)
    //     std::cout << key << " found at index = " << keyFoundAt << std::endl;
    // else
    //     std::cout << "Couldn't find key" << std::endl;

    // std::cout << "Number of elements smaller or equal to " << key << " = " << countSmallOrEqualElements(arr, key) << std::endl;

    // std::vector<std::vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 0, 0, 1}};

    // std::vector<long int> arr{2147483647, -2147483648, -2147483648, 0, 1};
    // vector<vector<long int> > res = threeSum(arr);
    // for(auto ar : res)
    // {
    //     for(auto x : ar)
    //     {
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::vector<int> A{-4, 3};
    std::vector<int> B{-2, -2};

    merge(A, B);
    for(auto x : A)
        std::cout << x << ", ";
    std::cout << std::endl;

    return 0;
}
