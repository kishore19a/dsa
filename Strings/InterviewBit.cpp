#include <iostream>
#include <string>
#include <vector>

using namespace std;

// std::vector<std::string> splitString(std::string& line)
// {
//     std::string str;
//     std::vector<std::string> strVec;

//     for(auto x : line)
//     {
//         if(x == " ")
//         {
//             strVec.push_back(str);
//             str.erase();
//         }
//         else
//             str += x;
//     }

//     return strVec;
// }

// std::vector<std::string> getJustified(std::string& line, int L)
// {
//     std::vector<std::string> allWords(splitString(line));
//     std::string str;

//     int i{0};

//     while(i < allWords.size())
//     {
//         if(allWords[i].length + )
//     }
// }

int main(int argc, char const *argv[])
{
    std::string S{"       fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq                 "};
    std::string ans{"iwfcqq igjgip myq sn dqmy qfho sswz ouhsuhf kxorifrhubk jsx ulc osdt fwbpudnbrozzifml"};
    int n = S.length();
    std::string str, rev;
    
    for(int i = 0; i < n; i++)
    {
        if(S[i] != ' ')
            str += S[i];
        else
        {
            if(!str.empty())
            {
                rev = str + " " + rev;
                str.erase();
            }
        }
    }
    
    if(!str.empty())
        rev = str + " " + rev;
    
    string revFin(rev.begin(), rev.end()-1);

    std::cout << revFin << std::endl;
    
    if(revFin == ans)
        std::cout << "they are equal" << std::endl;
    else
        std::cout << "They are not equal" << std::endl;

    return 0;
}
