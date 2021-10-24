#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <algorithm>

enum TravTypes
{
    inorder,
    preorder,
    postorder
};

struct Node
{
    int data;
    Node* left;
    Node* right;
    int hvNo{0};

    Node() : left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree()
{
    int n;
    std::cout << "Enter node val, Enter -1 to stop: ";
    std::cin >> n;

    if(n == -1) return nullptr;

    Node* root = new Node(n);

    std::cout << "Building left subtree of node " << n << std::endl;
    root->left = buildTree();

    std::cout << "Building right subtree of node " << n << std::endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root)
{
    if(root == nullptr) return;

    std::queue<Node*> travQ;
    travQ.push(root);

    while (!travQ.empty())
    {
        Node* front = travQ.front();
        travQ.pop();

        std::cout << front->data << " ";

        if(front->left != nullptr) travQ.push(front->left);
        if(front->right != nullptr) travQ.push(front->right);
    }

    std::cout << std::endl;
}

void levelOrderTraversalLineByLine(Node* root)
{
    if(root == nullptr) return;

    std::queue<Node*> travQ;
    travQ.push(root);

    while (!travQ.empty())
    {
        int size = travQ.size();

        for (int i = 0; i < size; i++)
        {
            Node* front = travQ.front();
            travQ.pop();

            std::cout << front->data << " ";

            if(front->left != nullptr) travQ.push(front->left);
            if(front->right != nullptr) travQ.push(front->right);
        }
        std::cout << std::endl;
    }
}

void traverseTree(Node* root, TravTypes travAlg)
{
    switch (travAlg)
    {
    case inorder:
            if(root != nullptr)
            {
                traverseTree(root->left, inorder);
                std::cout << root->data << " ";
                traverseTree(root->right, inorder);
            }
        break;
    
    case preorder:
            if(root != nullptr)
            {
                std::cout << root->data << " ";
                traverseTree(root->left, preorder);
                traverseTree(root->right, preorder);
            }
        break;

    case postorder:
            if(root != nullptr)
            {
                traverseTree(root->left, postorder);
                traverseTree(root->right, postorder);
                std::cout << root->data << " ";
            }
        break;
    
    default:
        break;
    }
}

int heightOfTree(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return 1 + std::max(heightOfTree(root->left), heightOfTree(root->right));
}

void nodesAtDistanceK(Node* root, int K, int i)
{
    if(root == nullptr) return;

    if(i == K)
        std::cout << root->data << " ";
    else
    {
        nodesAtDistanceK(root->left, K, i+1);
        nodesAtDistanceK(root->right, K, i+1);
    }
}

int sizeOfTree(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return (1 + sizeOfTree(root->left) + sizeOfTree(root->right));
}

int maxOfTree(Node* root)
{
    if(root == nullptr)
        return INT_MIN;
    else
        return std::max({root->data, maxOfTree(root->left), maxOfTree(root->right)});
}

void printLeftViewOfTree(Node* root)
{
    if(root == nullptr) return;

    std::queue<Node*> travQ;
    travQ.push(root);

    while(!travQ.empty())
    {
        int size = travQ.size();
        std::cout << travQ.front()->data << " ";

        for(int i = 0; i < size; i++)
        {
            Node* front = travQ.front();
            travQ.pop();

            if(front->left != nullptr) travQ.push(front->left);
            if(front->right != nullptr) travQ.push(front->right);
        }
    }

    std::cout << std::endl;
}

bool childrenSumProperty(Node* root)
{
    if(root == nullptr) return false;

    if(root->left == nullptr && root->right == nullptr) return true;
    else if(root->left == nullptr && root->right != nullptr && root->data == root->right->data && childrenSumProperty(root->right)) return true;
    else if(root->right == nullptr && root->left != nullptr && root->data == root->left->data && childrenSumProperty(root->left)) return true;
    else if(root->left != nullptr && root->right != nullptr && root->data == root->left->data + root->right->data && childrenSumProperty(root->left) && childrenSumProperty(root->right)) return true;
    else return false;
}

int balancedBinaryTree(Node* root)
{
    if(root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr) return 0;
    else if (root->left == nullptr && root->right != nullptr) return (balancedBinaryTree(root->right) + 1);
    else if (root->left != nullptr && root->right == nullptr) return (-1 + balancedBinaryTree(root->left));
    else return (balancedBinaryTree(root->right) - balancedBinaryTree(root->left));
}

int maxWidthOfTree(Node* root)
{
    if(root == nullptr) return 0;
    std::queue<Node*> travQ;
    travQ.push(root);

    int maxWidth(INT_MIN);

    while(!travQ.empty())
    {
        int size = travQ.size();
        maxWidth = std::max(maxWidth, size);

        for (int i = 0; i < size; i++)
        {
            Node* front = travQ.front();
            travQ.pop();

            if(front->left != nullptr) travQ.push(front->left);
            if(front->right != nullptr) travQ.push(front->right);
        }        
    }

    return maxWidth;
}

Node *dllRoot{nullptr}, *prev{nullptr};

void convertTreeToDll(Node* root)
{
    if(root != nullptr)
    {
        convertTreeToDll(root->left);

        if(dllRoot == nullptr)
            dllRoot = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }

        prev = root;
        convertTreeToDll(root->right);
    }
}

void spiralTraversal(Node* root)
{
    if(root == nullptr) return;
    std::deque<Node*> spTrav;
    spTrav.push_back(root);

    int i{1};

    while (!spTrav.empty())
    {
        int size = spTrav.size();
        if(i % 2 == 0)
        {
            for(int j = 0; j < size; j++)
            {
                Node* node = spTrav.back();
                spTrav.pop_back();

                std::cout << node->data << " ";

                if(node->right != nullptr) spTrav.push_front(node->right);
                if(node->left != nullptr) spTrav.push_front(node->left);
            }
        }
        else
        {
            for(int j = 0; j < size; j++)
            {
                Node* node = spTrav.front();
                spTrav.pop_front();

                std::cout << node->data << " ";

                if(node->left != nullptr) spTrav.push_back(node->left);
                if(node->right != nullptr) spTrav.push_back(node->right);
            }
        }
        i++;
        std::cout << std::endl;
    }
}

int res{0};
int diameterOfTree(Node* root)
{
    if(root == nullptr)
        return 0;

    int lh = diameterOfTree(root->left);
    int rh = diameterOfTree(root->right);

    res = std::max(res, 1+lh+rh);

    return (1 + std::max(lh, rh));
}

int main(int argc, char const *argv[])
{
    Node* root{nullptr};

    int n;
    std::cout << "Enter root node val, Enter -1 to stop: ";
    std::cin >> n;

    if(n != -1)
    {
        root = new Node(n);

        std::cout << "Building left subtree of root " << n << std::endl;
        root->left = buildTree();

        std::cout << "Building right subtree of root " << n << std::endl;
        root->right = buildTree();
    }

    // traverse tree - Depth first search
    traverseTree(root, preorder);
    std::cout << std::endl;

    // traverse tree - Breadth first search
    levelOrderTraversal(root);

    // traverse tree line by line - Breadth first search
    levelOrderTraversalLineByLine(root);
    
    // Height of tree
    std::cout << "Height of tree = " << heightOfTree(root) << std::endl;

    // Print all nodes at distance K from the root
    nodesAtDistanceK(root, 2, 0);
    std::cout << std::endl;

    // size of binary tree = total number of nodes in the tree
    std::cout << "Total number of nodes(size) of the tree = " << sizeOfTree(root);
    std::cout << std::endl;

    // max element in this tree
    std::cout << "Max element in this tree = " << maxOfTree(root);
    std::cout << std::endl;

    // Print left view of the tree
    printLeftViewOfTree(root);

    // Checking for children sum property
    if(childrenSumProperty(root))
        std::cout << "The tree follows children sum property" << std::endl;
    else
        std::cout << "The tree doesn't follow children sum property" << std::endl;

    // Checking for balanced binary tree
    if(std::abs(balancedBinaryTree(root)) > 1)
        std::cout << "Tree is not balanced" << std::endl;
    else
        std::cout << "Tree is balanced" << std::endl;

    // Max width of tree
    std::cout << "Max width of tree = " << maxWidthOfTree(root) << std::endl;

    // convert tree to DLL
    // convertTreeToDll(root);
    // Node* temp{dllRoot};
    // while (temp != nullptr)
    // {
    //     std::cout << temp->data << " ";
    //     temp = temp->right;
    // }
    // std::cout << std::endl;

    // spiral traversal of tree
    spiralTraversal(root);
    std::cout << std::endl;

    diameterOfTree(root);
    std::cout << "Diameter of tree = " << res << std::endl;

    return 0;
}
