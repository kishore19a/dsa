#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int i{0};
Node* constructTree(std::vector<int>& inorder, std::vector<int>& preorder)
{
    if(i >= preorder.size()) return nullptr;

    std::vector<int> left, right;
    int sel;

    Node* root = new Node(preorder[i]);

    for (int j = 0; j < inorder.size(); j++)
    {
        if(inorder[j] == preorder[i])
        {
            sel = j;
            break;
        }
        else
            left.push_back(inorder[j]);
    }

    for (int j = sel+1; j < inorder.size(); j++)
        right.push_back(inorder[j]);
    
    if(left.size() != 0)
    {
        i++;
        root->left = constructTree(left, preorder);
    }
    if(right.size() != 0)
    {
        i++;
        root->right = constructTree(right, preorder);
    }

    return root;
}

void printTree(Node* root)
{
    if(root != nullptr)
    {
        printTree(root->left);
        std::cout << root->data << " ";
        printTree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> inorder{3, 4, 6, 5, 1, 2, 0};
    std::vector<int> preorder{5, 4, 3, 6, 2, 1, 0};

    Node* root = constructTree(inorder, preorder);

    printTree(root);
    std::cout << std::endl;

    return 0;
}
