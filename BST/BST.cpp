#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
public:
    BST();
    ~BST();

    void buildBST(Node* root);
    void printBST(Node* root);
    bool search(Node* root, int key);
    Node* deleteKey(Node* root, int key);

    Node* floorOfKeyInBST(Node* root, int key);
private:
    
};

BST::BST()
{
}

BST::~BST()
{
}

void BST::buildBST(Node* root)
{
    if(root == nullptr) return;
    std::cout << "Rules to build the BST; enter values and it will be placed at appropriate position in the BST" << std::endl;
    std::cout << "Enter -1 to stop at any time" << std::endl;
    int n{0};

    while (true)
    {
        std::cin >> n;
        if(n == -1) break;

        Node *curr{root}, *prev{curr};

        while(curr != nullptr)
        {
            prev = curr;
            if(n > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(n > prev->data) prev->right = new Node(n);
        else prev->left = new Node(n);
    }
}

void BST::printBST(Node* root)
{
    if(root != nullptr)
    {
        printBST(root->left);
        std::cout << root->data << " ";
        printBST(root->right);
    }
}

bool BST::search(Node* root, int key)
{
    if(root == nullptr) return false;

    if(key == root->data) return true;
    else if(key > root->data) return search(root->right, key);
    else return search(root->left, key);
}

Node* BST::deleteKey(Node* root, int key)
{
    if(root == nullptr) return nullptr;

    if(root->data == key)
    {
        // Case 1: Leaf element
        if(root->left == nullptr && root->right == nullptr)
        {
            delete(root); root = nullptr; return nullptr;
        }
        // Case 2: left child is null
        else if(root->left == nullptr)
        {
            Node* retNode = root->right;
            delete(root); root = nullptr; return retNode;
        }
        // Case 3: right child is null
        else if(root->right == nullptr)
        {
            Node* retNode = root->left;
            delete(root); root = nullptr; return retNode;
        }
        // Case 4: both nodes are not null
        else
        {
            Node* retNode = root->left;
            retNode->right = root->right;
            delete(root); root = nullptr; return retNode;
        }
    }
    else if(key > root->data) root->right = deleteKey(root->right, key);
    else root->left = deleteKey(root->left, key);
}

Node* BST::floorOfKeyInBST(Node* root, int key)
{
    if(root == nullptr) return root;

    Node *curr{root}, *prev{root};
    while (curr != nullptr)
    {
        prev = curr;
        if(key == curr->data)
            return curr;
        else if(key > curr->data)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    if(key < prev->data) return nullptr;
    else return prev;
}

int main()
{
    Node* root;
    int n;

    std::cout << "Enter root node" << std::endl;
    std::cin >> n;

    if(n != -1) root = new Node(n);
    else root = nullptr;

    BST bst;
    bst.buildBST(root);

    bst.printBST(root);
    std::cout << std::endl;

    // std::cout << "Enter an element to search in the BST" << std::endl;
    // std::cin >> n;
    // if(bst.search(root, n))
    //     std::cout << n << " found in BST" << std::endl;
    // else
    //     std::cout << n << " not found in BST" << std::endl;

    // std::cout << "Enter an element to delete in the BST" << std::endl;
    // std::cin >> n;
    // root = bst.deleteKey(root, n);
    // bst.printBST(root);
    // std::cout << std::endl;

    std::cout << "Enter an element to find floor of in the BST" << std::endl;
    std::cin >> n;
    Node* floorNode = bst.floorOfKeyInBST(root, n);
    if(floorNode != nullptr) std::cout << "Floor of " << n << " = " << floorNode->data << std::endl;
    else std::cout << "Floor of " << n << " not found" << std::endl;

    return 0;
}
