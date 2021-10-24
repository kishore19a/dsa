#include <iostream>
#include <map>

struct Node
{
    int key;
    Node* left{nullptr};
    Node* right{nullptr};
    int hd{0};

    Node(int val)
    {
        key = val;
    }
};

int horizontalDistance(Node *node)
{
    if(node == nullptr) return 0;
    else return node->hd;
}

Node* maxNode(Node* root)
{
    Node *curr{root}, *prev{curr};
    while(curr != nullptr)
    {
        prev = curr;
        curr = curr->right;
    }

    return prev;
}

Node* minNode(Node* root)
{
    Node *curr{root}, *prev{curr};
    while(curr != nullptr)
    {
        prev = curr;
        curr = curr->left;
    }
    return prev;
}

bool checkIfBST(Node* root)
{
    if(root ==  nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    else if(root->left != nullptr && root->right == nullptr)
    {
        if((root->key > root->left->key) && checkIfBST(root->left) && (root->key > maxNode(root->left)->key))
            return true;
    }
    else if(root->left == nullptr && root->right != nullptr)
    {
        if((root->key < root->right->key) && checkIfBST(root->right) && (root->key < minNode(root->right)->key))
            return true;
    }
    else if(root->left != nullptr && root->right != nullptr)
    {
        if((root->key > root->left->key) && (root->key < root->right->key) && checkIfBST(root->left) && 
            checkIfBST(root->right) && (root->key > maxNode(root->left)->key) && (root->key < minNode(root->right)->key))
            return true;
    }

    return false;
}

void setBottomViewOfTree(Node *root, int hd, std::map<int, int>& hv)
{
    if(root != nullptr)
    {
        setBottomViewOfTree(root->left, hd-1, hv);
        root->hd = hd;
        hv[root->hd] = root->key;
        setBottomViewOfTree(root->right, hd+1, hv);
    }
}

void setTopViewOfTree(Node *root, int hd, std::map<int, int>& hv)
{
    if(root != nullptr)
    {
        setTopViewOfTree(root->left, hd-1, hv);
        root->hd = hd;
        auto found = hv.find(hd);
        if(found == hv.end())
            hv[root->hd] = root->key;
        setTopViewOfTree(root->right, hd+1, hv);
    }
}

void printTree(Node *root)
{
    if(root != nullptr)
    {
        printTree(root->left);
        std::cout << root->key << " ";
        printTree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printTree(root);
    std::cout << std::endl;

    std::cout << "Check if the tree is BST" << std::endl;
    if(checkIfBST(root))
        std::cout << "Tree is BST" << std::endl;
    else
        std::cout << "Tree is not BST" << std::endl;

    std::map<int, int> bv;
    setBottomViewOfTree(root, 0, bv);
    for (auto& p : bv)
        std::cout << p.second << " " ;
    std::cout << std::endl; 

    std::map<int, int> tv;
    setTopViewOfTree(root, 0, tv);
    for (auto& p : tv)
        std::cout << p.second << " " ;
    std::cout << std::endl;    

    return 0;
}
