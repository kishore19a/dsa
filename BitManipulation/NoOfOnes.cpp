#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    // int res{0};
    // unsigned int A{4294967295}, revA{0};
    // std::string revBinA;
    // while(A != 0)
    // {
    //     if((A & 1) != 0) revBinA = revBinA + "1";
    //     else revBinA = revBinA + "0";
    //     A = A >> 1;
    //     res++;
    // }

    // int pos{0};
    // for (int i = revBinA.size()-1; i >= 0; i--)
    // {
    //     if(revBinA[i] == '1') revA = revA + std::pow(2, pos);
    //     pos++;
    // }


    // unsigned int finRev = revA<<(32-res);

    std::vector<int> A({-533, -666, -500, 169, 724, 478, 358, -38, -536, 705, -855, 281, -173, 961, -509, -5, 942, -173, 436, -609, -396, 902, -847, -708, -618, 421, -284, 718, 895, 447, 726, -229, 538, 869, 912, 667, -701, 35, 894, -297, 811, 322});
    int B{369};

    std::sort(A.begin(), A.end());

    for (auto a : A)
    {
        std::cout << a << ", ";
    }
    std::cout << std::endl;

    bool found{false}; int j{A.size() - 1};
    for (int i = 0; i < A.size()-1; i++)
    {
        for (; j > i; j--)
        {
            std::cout << i << " , " << j << std::endl;
            if(A[j] - A[i] == std::abs(B))
            {
                found = true;
                std::cout << "Difference between " << A[j] << " and " << A[i] << " = " << std::abs(B);
                break;
            }
            if(A[j] - A[i] < std::abs(B)) break;
        }

        if(j == i) j = A.size() - 1;
        if(found) break;
    }
    
    if(!found) std::cout << "No such pair exists" << std::endl;

    return 0;
}
