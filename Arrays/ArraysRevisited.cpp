#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

int secondLargestElementIndex(const std::vector<int>& arr)
{
    int largestIndex{-1}, secondLargestIndex{-1}, largest{INT_MIN}, secondLargest{INT_MIN};

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > largest)
        {
            secondLargestIndex = largestIndex;
            largestIndex = i;

            secondLargest = largest;
            largest = arr[i];
        }
        else
        {
            if(arr[i] != largest && arr[i] > secondLargest)
            {
                secondLargestIndex = i;
                secondLargest = arr[i];
            }
        }
    }

    if(largest == secondLargest)
        return -1;
    else     
        return secondLargestIndex;
}

bool isArraySorted(const std::vector<int>& arr)
{
    bool sorted{true};

    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < arr[i-1])
            return false;
    }

    return sorted;
}

void reverseArray(std::vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n/2; i++)
        std::swap(arr[i], arr[n-i-1]);    
}

int removeDuplicatesFromSOrtedArray(std::vector<int>& arr)
{
    if(arr.size() == 0) return 0;

    int k{1};
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > arr[i-1])
        {
            arr[k] = arr[i];
            k++;
        }
    }
    
    return k;
}

void moveAllToZerosToEnd(std::vector<int>& arr)
{
    int k{0};
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    for (; k < arr.size(); k++)
        arr[k] = 0;    
}

std::vector<int> leftRotateArrayByD(std::vector<int>& arr, int d)
{
    std::vector<int> rotatedArray(arr.size());
    d = d % arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        int idx = (i - d + arr.size()) % arr.size();
        rotatedArray[idx] = arr[i];
    }
    
    return rotatedArray;
}

void leadersInTheArray(std::vector<int>& arr)
{
    std::stack<int> leaders;
    leaders.push(arr[arr.size() - 1]);

    for(int i = arr.size() - 2; i >= 0; i--)
    {
        if(arr[i] > leaders.top())
            leaders.push(arr[i]);
    }

    while(!leaders.empty())
    {
        std::cout << leaders.top() << ", ";
        leaders.pop();
    }
    std::cout << std::endl;
}

int maxDifferenceProblemWithOrder(std::vector<int>& arr)
{
    if(arr.size() < 2) return -1;

    int maxDiff = arr[1] - arr[0];
    int minVal = arr[0];

    for(int i = 2; i < arr.size(); i++)
    {
        maxDiff = std::max(maxDiff, (arr[i] - minVal));
        minVal = std::min(arr[i], minVal);
    }

    return maxDiff;
}

void printFrequenciesInSortedArray(const std::vector<int>& arr)
{
    int currElem{arr[0]}, currElemFreq{1};
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] > currElem)
        {
            std::cout << currElem << " -> " << currElemFreq << std::endl;
            currElemFreq = 1;
            currElem = arr[i];
        }
        else
            currElemFreq++;
    }

    std::cout << currElem << " -> " << currElemFreq << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{10, 10, 10, 10, 20, 20, 30, 30, 30};

    std::cout << "Original array: " << std::endl;
    for(auto x : arr)
        std::cout << x << ", ";
    std::cout << std::endl;

    // int secondLargestIndex = secondLargestElementIndex(arr);
    // if(secondLargestIndex != -1)
    //     std::cout << "Second largest element at index " << secondLargestIndex << " = " << arr[secondLargestIndex] << std::endl;
    // else
    //     std::cout << "Second largest element not present" << std::endl;

    // std::cout << "Is the array sorted? " << (isArraySorted(arr)? "yes" : "no") << std::endl;

    // int sizeOfUniqueArray = removeDuplicatesFromSOrtedArray(arr);
    // std::cout << "Size of unique array = " << sizeOfUniqueArray << std::endl;
    // for (int i = 0; i < sizeOfUniqueArray; i++)
    //     std::cout << arr[i] << ", ";
    // std::cout << std::endl; 

    // moveAllToZerosToEnd(arr);
    // for(auto x : arr)
    //     std::cout << x << ", ";
    // std::cout << std::endl;

    // std::cout << "Printing reversed array: " << std::endl;
    // reverseArray(arr);
    // for(auto x : arr)
    //     std::cout << x << ", ";
    // std::cout << std::endl;

    // int d{12};
    // std::vector<int> rotatedArray{leftRotateArrayByD(arr, d)};
    // std::cout << "Left rotating the array by " << d << std::endl;
    // for(auto x : rotatedArray)
    //     std::cout << x << ", ";
    // std::cout << std::endl;

    // std::cout << "Printing leaders in the array: ";
    // leadersInTheArray(arr);

    // std::cout << "Maximum difference problem with order: " << maxDifferenceProblemWithOrder(arr) << std::endl;

    printFrequenciesInSortedArray(arr);
    
    return 0;
}
