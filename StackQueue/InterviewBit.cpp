#include <iostream>
#include <stack>

std::string simplifyDirPath(std::string& path)
{
    std::stack<char> stk; std::string res;
    for(int i = 0; i < path.length(); i++)
    {
        if (stk.empty())
        {
            stk.push(path[i]);
        }
        else
        {
            if(path[i] == '/' || path[i] == '.')
            {
                char top = stk.top();
                if (top == '/' && path[i] == '/')
                {
                    continue;
                }
                else if (top == '/' && path[i] == '.')
                {
                    stk.push(path[i]);
                }
                else if(top == '.' && path[i] == '.')
                {
                    char top;
                    if(!stk.empty()) stk.pop(); 
                    if(!stk.empty()) stk.pop();
                    if(!stk.empty()) top = stk.top();
                    while(!stk.empty() && top != '/')
                    {
                        stk.pop();
                        top = stk.top();
                    }
                }
                else if(top == '.' && path[i] == '/')
                {
                    if(!stk.empty()) stk.pop();
                }
                else
                {
                    stk.push(path[i]);
                }
            }
            else
            {
                stk.push(path[i]);
            }
        }
    }

    while(!stk.empty())
    {
        char top = stk.top();
        res = top + res;
        stk.pop();
    }

    int n = res.length();
    if(n > 1 && res[n-1] == '/')
        res = res.substr(0, n-1);

    if(res.empty())
        return "/";

    return res;
}

int main(int argc, char const *argv[])
{
    std::string path = "/..";
    std::string simple(simplifyDirPath(path));

    std::cout << simple << std::endl;

    return 0;
}
