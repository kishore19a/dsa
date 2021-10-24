#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* bstInsert(Node* root, int val)
{
    if(root == nullptr)
        return (new Node(val));
    else
    {
        if(val < root->data)
            root->left = bstInsert(root->left, val);
        else
            root->right = bstInsert(root->right, val);
    }

    return root;
}

bool bstSearch(Node* root, int val)
{
    if(root == nullptr)
        return false;
    else
    {
        if(root->data == val)
            return true;
        else if(root->data > val)
            return bstSearch(root->left, val);
        else
            return bstSearch(root->right, val);
    }

    return false;
}

Node* getSuccessor(Node* root)
{
    if(root == nullptr) return nullptr;
    Node* curr = root->right;
    while(curr != nullptr && curr->left != nullptr)
        curr = curr->left;

    return curr;
}

Node* bstDelete(Node* root, int val)
{
    if(root != nullptr)
    {
        if(root->data > val)
            root->left = bstDelete(root->left, val);
        else if(root->data < val)
            root->right = bstDelete(root->right, val);
        else
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete(root);
                root = nullptr;
                return root;
            }
            else if(root->left == nullptr && root->right != nullptr)
            {
                Node* right = root->right;
                delete(root);
                root = nullptr;
                return right;
            }
            else if(root->left != nullptr && root->right == nullptr)
            {
                Node* left = root->left;
                delete(root);
                root = nullptr;
                return left;
            }
            else
            {
                Node* succ = getSuccessor(root);
                root->data = succ->data;
                root->right = bstDelete(root->right, succ->data);
                return root;
            }
        }
    }

    return root;
}

Node* bstFloor(Node* root, int val)
{
    Node* res{root};
    while(root != nullptr)
    {
        if(root->data == val)
            return root;
        else if(root->data > val)
        {
            root = root->left;
            res = root;
        }
        else
        {
            root = root->right;
            if(root != nullptr) res = root;
        }
    }

    return res;
}

Node* bstCeil(Node* root, int val)
{
    Node* res{root};
    while(root != nullptr)
    {
        if(root->data == val)
            return root;
        else if(root->data > val)
        {
            root = root->left;
            if(root != nullptr) res = root;
        }
        else
        {
            root = root->right;
            res = root;
        }
    }

    return res;
}

// inorder
void traverseBst(Node* root)
{
    if(root != nullptr)
    {
        traverseBst(root->left);
        std::cout << root->data << " ";
        traverseBst(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node* root{nullptr};
    root = bstInsert(root, 10);
    root = bstInsert(root, 5);
    root = bstInsert(root, 15);
    root = bstInsert(root, 12);
    root = bstInsert(root, 30);

    traverseBst(root);
    std::cout << std::endl;

    if(bstSearch(root, 17))
        std::cout << "Found node" << std::endl;
    else
        std::cout << "Node not found" << std::endl;

    root = bstDelete(root, 20);
    traverseBst(root);
    std::cout << std::endl;

    Node* floor = bstFloor(root, 100);
    if(floor != nullptr)
        std::cout << "Floor = " << floor->data << std::endl;
    else
        std::cout << "Floor doesn't exist" << std::endl;

    Node* ceil = bstCeil(root, 100);
    if(ceil != nullptr)
        std::cout << "Ceil = " << ceil->data << std::endl;
    else
        std::cout << "Ceil doesn't exist" << std::endl;

    return 0;
}
