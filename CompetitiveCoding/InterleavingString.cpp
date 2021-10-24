#include <iostream>

bool interleavingString(std::string& s1, std::string& s2, std::string& s3, int i, int j, int k, std::string& lastMatchedString)
{
    if(i == s1.length())
    {
        for (; j < s2.length(); j++, k++)
        {
            std::cout << "After s2[" << j << "] = " <<  s2[j] << " and s3[" << k << "] = " << s3[k] << std::endl; 
            if(s2[j] != s3[k]) return false;
        }
        return true;
    }

    if(j == s2.length())
    {
        for (; i < s1.length(); i++, k++)
        {
            std::cout << "After s1[" << i << "] = " <<  s1[i] << " and s3[" << k << "] = " << s3[k] << std::endl;
            if(s1[i] != s3[k]) return false;
        }
        return true;
    }

    if(s1[i] == s3[k] && s2[j] == s3[k])
    {
        if(lastMatchedString == s1)
        {
            std::cout << "s1[" << i << "] = " <<  s1[i] << " and s3[" << k << "] = " << s3[k] << std::endl;
            lastMatchedString = s1;
            return interleavingString(s1, s2, s3, i+1, j, k+1, lastMatchedString);
        }
        else
        {
            std::cout << "s2[" << j << "] = " <<  s2[j] << " and s3[" << k << "] = " << s3[k] << std::endl;
            lastMatchedString = s2;
            return interleavingString(s1, s2, s3, i, j+1, k+1, lastMatchedString);
        }
    }
    if(s1[i] == s3[k] && s2[j] != s3[k]) 
    {
        std::cout << "s1[" << i << "] = " <<  s1[i] << " and s3[" << k << "] = " << s3[k] << std::endl;
        lastMatchedString = s1;
        return interleavingString(s1, s2, s3, i+1, j, k+1, lastMatchedString);
    }
    else if (s2[j] == s3[k] && s1[i] != s3[k]) 
    {
        std::cout << "s2[" << j << "] = " <<  s2[j] << " and s3[" << k << "] = " << s3[k] << std::endl; 
        lastMatchedString = s2;
        return interleavingString(s1, s2, s3, i, j+1, k+1, lastMatchedString);
    }

    return false;
}

bool interleavingString(std::string& s1, std::string& s2, std::string& s3)
{
    if(s1.empty() && s2.empty() && s3.empty()) return true;
    if(s1.length() + s2.length() != s3.length()) return false;

    std::string lastMatchedString{};
    if(s1.empty() && !s2.empty())
    {
        if(s2[0] == s3[0]) lastMatchedString = s2;
    }
    else if (s2.empty() && !s1.empty())
    {
        if(s1[0] == s3[0]) lastMatchedString = s1;
    }
    else if (!s2.empty() && !s1.empty())
    {
        lastMatchedString = (s1[0] == s3[0])? s1 : s2;
    }

    std::cout << lastMatchedString << std::endl;
    
    if(lastMatchedString.empty()) return false;
    else return interleavingString(s1, s2, s3, 0, 0, 0, lastMatchedString);
}

int main(int argc, char const *argv[])
{
    std::string s1 = "aa";
    std::string s2 = "ab";
    std::string s3 = "aaba";

    if(interleavingString(s1, s2, s3))
        std::cout << "s1, s2, s3 form interleaving string" << std::endl;
    else
        std::cout << "s1, s2, s3 doesnot form interleaving string" << std::endl;

    return 0;
}
