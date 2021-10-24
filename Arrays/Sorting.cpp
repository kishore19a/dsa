#include <iostream>
#include <vector>

// Stable - Bubble Sort, Insertion Sort, Merge Sort
// Unstable - Selection Sort, Quick Sort, Heap Sort
// Intro Sort - hybrid of Insertion Sort, Quick Sort and Heap Sort

// ------ BUBBLE SORT --------
// n^2 algorithm
// in-place and stable
void bubbleSort(std::vector<int>& arr)
{
    bool anySwap{false};
    for (int i = arr.size() - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                anySwap = true;
            }
        }

        if(!anySwap) break;
    }
}

// ------ SELECTION SORT --------
// n^2 algorithm
// much more memory efficient than other sorting algorithms
// in-place and unstable
void selectionSort(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex{i};
        for(int j = i+1; j < arr.size(); j++)
        {
            if(arr[j] < arr[minIndex]) minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

// ------ INSERTION SORT --------
// n^2 algorithm
// In place and stable
// O(n) in best case {already sorted}
// Best for small arrays {used in hybrid algoritms like Tim Sort (Python) and Intro Sort (C++)}
void insertionSort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int indexOfInterest{i};
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[indexOfInterest] < arr[j])
            {
                std::swap(arr[indexOfInterest], arr[j]);
                indexOfInterest = j;
            }
            else
                break;
        }
    }    
}

// ------ MERGE SORT --------
// O(nlogn) - time complexity
// O(n) - auxillary space - not inplace
// Stable Algorithm
// Quick sort outperform it
void merge(std::vector<int>& arr, int low, int mid, int high)
{
    int i{low}, j{mid+1}, k{0};
    std::vector<int> arr1(high-low+1);
    while (i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            arr1[k] = arr[i];
            i++; k++;
        }
        else
        {
            arr1[k] = arr[j];
            j++; k++;
        }
    }

    while(i <= mid)
    {
        arr1[k] = arr[i];
        i++; k++;
    }

    while(j <= high)
    {
        arr1[k] = arr[j];
        j++; k++;
    }
    
    int m{low}, n{0};
    while(m <= high)
    {
        arr[m] = arr1[n];
        m++; n++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

// ------ MERGE 2 SORTED ARRAYS --------
void mergeSortedArrays(std::vector<int>& arr1, std::vector<int>& arr2)
{
    int i{0}, j{0}, k{0};
    std::vector<int> arr3(arr1.size() + arr2.size());
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++; k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++; k++;
        }
    }

    if(i < arr1.size())
    {
        while (i < arr1.size())
        {
            arr3[k] = arr1[i];
            i++; k++;
        }        
    }
    else
    {
        while (j < arr2.size())
        {
            arr3[k] = arr2[j];
            j++; k++;
        }        
    }

    for(auto x : arr3)
        std::cout << x << ", ";
    std::cout << std::endl;
}

// ------ INTERSECTION OF 2 SORTED ARRAYS -------
std::vector<int> intersectionOf2SortedArray(std::vector<int>& arr1, std::vector<int>& arr2)
{
    int i{0}, j{0};
    std::vector<int> arr3;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr1[i] > arr2[j])
            j++;
        else
        {
            if(arr3.size() > 0)
            {
                if(arr1[i] != arr3.back())
                    arr3.push_back(arr1[i]);
            }
            else
                arr3.push_back(arr1[i]);

            i++; j++;
        }
    }

    return arr3;
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{2, 8, 9, 4, 5, 34, 1, 3, 6, 7};

    std::cout << "Original array : ";
    for(auto x : arr)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "Sorted array : ";
    // bubbleSort(arr);
    // selectionSort(arr);
    // insertionSort(arr);
    mergeSort(arr, 0, arr.size()-1);
    for(auto x : arr)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "------------------------------------------" << std::endl;
    std::vector<int> intArr1{3, 5, 10, 10, 10, 15, 15, 20};
    std::vector<int> intArr2{5, 10, 10, 15, 30};
    std::vector<int> intArr = intersectionOf2SortedArray(intArr1, intArr2);
    for(auto x : intArr)
        std::cout << x << ", ";
    std::cout << std::endl;

    // std::vector<int> arr1{10, 15, 20};
    // std::vector<int> arr2{5, 6, 6, 15};
    // mergeSortedArrays(arr1, arr2);

    // std::cout << "------------------------------------------" << std::endl;
    // std::vector<int> arr3{10, 15, 20, 11, 30};
    // std::cout << "Original array : ";
    // for(auto x : arr3)
    //     std::cout << x << ", ";
    // std::cout << std::endl;

    // std::cout << "Sorted array : ";
    // merge(arr3, 0, 2, 4);
    // for(auto x : arr3)
    //     std::cout << x << ", ";
    // std::cout << std::endl;

    return 0;
}
