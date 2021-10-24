#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& vec, int elem)
{
    int start{0}, end{vec.size() - 1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == elem) return mid;
        else if(vec[mid] > elem) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int binarySearchRecc(const std::vector<int>& vec, int elem, int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == elem) return mid;
        else if(vec[mid] > elem) return binarySearchRecc(vec, elem, start, mid - 1);
        else return binarySearchRecc(vec, elem, mid + 1, end);
    }

    return -1;
}

int indexOfFirstOccuranceInSortedArray(const std::vector<int>& vec, int elem)
{
    int start{0}, end{vec.size() - 1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == elem)
        {
            mid--;
            while(mid >= 0 && vec[mid] == elem)
                mid--;
            return (mid + 1);
        }
        else if(vec[mid] > elem) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int indexOfLastOccuranceInSortedArray(const std::vector<int>& vec, int elem)
{
    int start{0}, end{vec.size() - 1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == elem)
        {
            mid++;
            while(mid < vec.size() && vec[mid] == elem)
                mid++;
            return (mid - 1);
        }
        else if(vec[mid] > elem) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int countNoOfOccuranceInSortedArray(const std::vector<int>& vec, int elem)
{
    int start{0}, end{vec.size() - 1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == elem)
        {
            int found{mid}, count{1};
            mid++;
            while(mid < vec.size() && vec[mid] == elem)
            {
                mid++;
                count++;
            }

            mid = found - 1;
            while(mid >= 0 && vec[mid] == elem)
            {
                mid--;
                count++;
            }
            
            return count;
        }
        else if(vec[mid] > elem) end = mid - 1;
        else start = mid + 1;
    }

    return 0;
}

int sqt(int x)
{
    int start{1}, end{x}, ans{-1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if(mid*mid == x) return mid;
        else if(mid*mid > x) end = mid - 1;
        else start = mid + 1;
    }

    return mid;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec{5, 8, 10};
    int elem{7};
    int elemIdx = binarySearch(vec, elem);

    int start{0}, end{vec.size() - 1};
    int elemIdxRecc = binarySearchRecc(vec, elem, start, end);

    std::cout << elem << " found at index (iterative) = " << elemIdx << std::endl;
    std::cout << elem << " found at index (reccursive) = " << elemIdx << std::endl;

    int idxOfFirstOccr = indexOfFirstOccuranceInSortedArray(vec, elem);
    std::cout << "Index of first occurnce of " << elem << " = " << idxOfFirstOccr << std::endl;

    int idxOfLastOccr = indexOfLastOccuranceInSortedArray(vec, elem);
    std::cout << "Index of last occurnce of " << elem << " = " << idxOfLastOccr << std::endl;

    int noOfOccr = countNoOfOccuranceInSortedArray(vec, elem);
    std::cout << "Number of occurnce of " << elem << " = " << noOfOccr << std::endl;

    std::cout << "sqrt(" << 1 << ") = " <<  sqt(1) << std::endl;
    std::cout << "sqrt(" << 2 << ") = " <<  sqt(2) << std::endl;
    std::cout << "sqrt(" << 3 << ") = " <<  sqt(3) << std::endl;
    std::cout << "sqrt(" << 4 << ") = " <<  sqt(4) << std::endl;
    std::cout << "sqrt(" << 5 << ") = " <<  sqt(5) << std::endl;
    std::cout << "sqrt(" << 6 << ") = " <<  sqt(6) << std::endl;
    std::cout << "sqrt(" << 7 << ") = " <<  sqt(7) << std::endl;
    std::cout << "sqrt(" << 8 << ") = " <<  sqt(8) << std::endl;
    std::cout << "sqrt(" << 9 << ") = " <<  sqt(9) << std::endl;
    std::cout << "sqrt(" << 10 << ") = " <<  sqt(10) << std::endl;
    std::cout << "sqrt(" << 11 << ") = " <<  sqt(11) << std::endl;
    std::cout << "sqrt(" << 12 << ") = " <<  sqt(12) << std::endl;

    return 0;
}
