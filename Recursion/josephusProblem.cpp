#include <iostream>
#include <vector>

void killPerson(std::vector<int>& arr, int start, int numKilled, int k)
{
    if(numKilled == arr.size()-1)
        return;

    int killIndex = (start + k - 1) % arr.size();
    arr[killIndex] = 0;
    start = killIndex + 1;
    numKilled++;
    std::cout << "killIndex = " << killIndex << " , start = " << start << " , numKilled = " << numKilled << std::endl;
    killPerson(arr, start, numKilled, k);
}

int main(int argc, char const *argv[])
{
    int numElems{4}, k{2};
    std::vector<int> arr(numElems, 1);
    killPerson(arr, 0, 0, k);

    for(int i = 0; i < numElems; i++)
    {
        if(arr[i] == 1)
        {
            std::cout << "Person not killed = " << i << std::endl;
        }
    }

    return 0;
}
