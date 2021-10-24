#include <iostream>
#include <string>

std::string rmvConsDup(const std::string& str)
{
    std::string strMod{};
    int n = str.length();

    if(n == 0) return strMod;
    strMod = str[0];

    for(int i = 1; i < n; i++)
    {
        if(str[i] == strMod.back())
            continue;
        else
            strMod += str[i];
    }

    return strMod;
}

std::string rmvConsDup2(std::string A, int B)
{
    std::string strMod{};
    int n = A.length();

    if(n == 0) return strMod;

    char charOfInterest = A[0];
    int countOfCharOfInterest = 1;

    for(int i = 1; i < n; i++)
    {
        if(A[i] == charOfInterest)
            countOfCharOfInterest++;
        else
        {
            if(countOfCharOfInterest != B)
            {
                strMod.append(countOfCharOfInterest, charOfInterest);
            }
            
            charOfInterest = A[i];
            countOfCharOfInterest = 1;
        }
    }

    if(countOfCharOfInterest != B)
        strMod.append(countOfCharOfInterest, charOfInterest);

    return strMod;
}

int main(int argc, char const *argv[])
{
    std::string str{"geeksforgeeks"};
    std::string lStr = rmvConsDup(str);
    std::string lStr2 = rmvConsDup2(str, 2);

    std::cout << str << " = " << lStr << std::endl;
    std::cout << str << " = " << lStr2 << std::endl;
    return 0;
}
