#include <iostream>
#include <stack>
#include <vector>

int main(int argc, char const *argv[])
{
    // Print all factors of a number
    int n{100};
    std::stack<int> list;

    for (int i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            std::cout << i << " , ";
            int comp = n / i;
            if(i != comp) list.push(comp);
        }
    }

    while (!list.empty())
    {
        std::cout << list.top() << " , ";
        list.pop();
    }
    
    std::cout << std::endl;
    return 0;
}
