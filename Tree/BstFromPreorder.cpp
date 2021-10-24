#include <iostream>
#include <vector>

bool isValidBst(std::vector<int>& preorder)
{
    if(preorder.size() == 0)
        return true;

    int root = preorder[0];
    std::vector<int> left, right;

    bool res{true};

    int i = 1;
    for(; i < preorder.size(); i++)
    {
        if(preorder[i] <= root)
        {
            left.push_back(preorder[i]);
        }
        else
            break;
    }

    for(; i < preorder.size(); i++)
    {
        right.push_back(preorder[i]);
    }

    for(int j = 0; j < left.size(); j++)
        if(left[j] > root)
            res = false;

    for(int j = 0; j < right.size(); j++)
        if(right[j] < root)
            res = false;


    return res && isValidBst(left) && isValidBst(right);
}

int main(int argc, char const *argv[])
{
    std::vector<int> preorder({40, 30, 35, 20, 80, 100});
    std::cout << "Is valid BST? " << (isValidBst(preorder)? "yes" : "no") << std::endl;
    return 0;
}
