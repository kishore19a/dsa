#include <iostream>
#include <vector>

std::vector<int> solve(int A, int B, int C, int D) {
    int i{0}, j{0}, k{0};

    std::vector<int> arr(D+1);
    arr[0] = 1;

    for(int l = 1; l <= D; l++)
    {
        std::cout << i << " , " << j << ", " << k << std::endl;
        std::cout << "Checking: (" << arr[i] << " * " << A << ") = " << arr[i]*A << ", (" << arr[j] << " * " << B << ") =" << arr[j]*B << ", (" << arr[k] << " * " << C << ") = " << arr[k]*C;
        if(arr[i]*A < arr[j]*B)
        {
            if(arr[i]*A < arr[k]*C)
            {
                arr[l] = arr[i]*A;
                i++;
            }
            else if(arr[i]*A > arr[k]*C)
            {
                arr[l] = arr[k]*C;
                k++;
            }
            else
            {
                arr[l] = arr[k]*C;
                k++; i++;
            }
        }
        else if(arr[i]*A > arr[j]*B)
        {
            if(arr[j]*B < arr[k]*C)
            {
                arr[l] = arr[j]*B;
                j++;
            }
            else if(arr[j]*B > arr[k]*C)
            {
                arr[l] = arr[k]*C;
                k++;
            }
            else
            {
                arr[l] = arr[k]*C;
                k++; j++;
            }
        }
        else
        {
            if(arr[j]*B == arr[k]*C)
                k++;
            
            arr[l] = arr[i]*A;
            i++; j++;
        }

        std::cout << ", res = " << arr[l] << std::endl;
    }

    std::vector<int> res(arr.begin()+1, arr.end());
    return res;
}

int main(int argc, char const *argv[])
{
    solve(3, 11, 7, 50);
    return 0;
}
