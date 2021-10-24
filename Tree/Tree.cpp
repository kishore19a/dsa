// Tree data structure
    // - used to represent hierarichal data
    // - nodes, root, leaf, subtree, children, parent, descendents, ancestors, internal nodes, degree
    // - Binary heap, Binary search tree, B and B+ tree, segment and binary index tree

/*
    10
    20  30
    40  -1  60  70
    -1  -1  -1  -1  -1  -1

    10 20 40 -1 -1 -1 30 60 -1 -1 70 -1 -1
*/

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <bits/stdc++.h>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

class Tree
{
public:
    Tree();
    ~Tree();

    void buildTree(Node* root);
    void printTree(Node* root);

    void inorderTraversal(Node* root);
    void preTraversal(Node* root);
    void postTraversal(Node* root);
    void levelOrderTraversal(Node* root);
    void spiralTraversal(Node* root);
    void levelOrderTraversalLineByLine(Node* root);
    void printNodeAtDistanceK(Node* root, int k, int i);
    void printLeftViewOfTree(Node* root);

    int getTreeHeight(Node* root);
    int sizeOfTree(Node* root);
    int maximumValueInTree(Node* root);

    bool childrenSumProperty(Node* root);
    int heightBalancedTree(Node* root);

    Node* buildTreeFromInOrderPreOrder(std::vector<int>& preorder, std::vector<int>& inorder, int rootNodeId);

private:
    void buildLeftSubTree(Node*& root);
    void buildRightSubTree(Node*& root);
};

Tree::Tree()
{
}

Tree::~Tree()
{
}

void Tree::buildRightSubTree(Node*& root)
{
    int n;
    // std::cout << "Insert right child of " << root->data << std::endl;
    std::cin >> n;

    if(n == -1) return;

    Node* newNode = new Node(n);
    root->right = newNode;

    buildLeftSubTree(newNode);
    buildRightSubTree(newNode);
}

void Tree::buildLeftSubTree(Node*& root)
{
    int n;
    // std::cout << "Insert left child of " << root->data << std::endl;
    std::cin >> n;

    if(n == -1) return;

    Node* newNode = new Node(n);
    root->left = newNode;

    buildLeftSubTree(newNode);
    buildRightSubTree(newNode);
}

void Tree::buildTree(Node* root)
{
    buildLeftSubTree(root);
    buildRightSubTree(root);
}

void Tree::inorderTraversal(Node* root)
{
    if(root != nullptr)
    {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void Tree::preTraversal(Node* root)
{
    if(root != nullptr)
    {
        std::cout << root->data << " ";
        preTraversal(root->left);
        preTraversal(root->right);
    }
}

void Tree::postTraversal(Node* root)
{
    if(root != nullptr)
    {
        postTraversal(root->left);
        postTraversal(root->right);
        std::cout << root->data << " ";
    }
}

void Tree::printTree(Node* root)
{
    inorderTraversal(root);
}

int Tree::getTreeHeight(Node* root)
{
    if(root == nullptr) return 0;

    return 1 + std::max(getTreeHeight(root->left), getTreeHeight(root->right));
}

int Tree::sizeOfTree(Node* root)
{
    if(root == nullptr) 
        return 0;
    else
        return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int Tree::maximumValueInTree(Node* root)
{
    if(root == nullptr) return INT_MIN;
    else return std::max({root->data, maximumValueInTree(root->left), maximumValueInTree(root->right)});
}

void Tree::printNodeAtDistanceK(Node* root, int k, int i)
{
    if(root == nullptr) return;
    if(i > k) return;

    if(i == k) std::cout << root->data << " ";
    else
    {
        printNodeAtDistanceK(root->left, k, i+1);
        printNodeAtDistanceK(root->right, k, i+1);
    }
}

void Tree::levelOrderTraversal(Node* root)
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
}

void Tree::levelOrderTraversalLineByLine(Node* root)
{
    if(root == nullptr) return;
    std::queue<Node*> travQ;
    travQ.push(root);

    while (!travQ.empty())
    {
        int travQSize = travQ.size();
        for (int i = 0; i < travQSize; i++)
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

void Tree::spiralTraversal(Node* root)
{
    if(root == nullptr) return;
    std::deque<Node*> levDeq;
    levDeq.push_back(root);

    int level = 1;

    while(!levDeq.empty())
    {
        if(level % 2 == 1)
        {
            for (int i = 0; i < levDeq.size(); i++)
            {
                std::cout << levDeq[i]->data << " ";
            }            
        }
        else
        {
            for (int i = levDeq.size() - 1; i >= 0; i--)
            {
                std::cout << levDeq[i]->data << " ";
            }
        }

        int size = levDeq.size();
        for (int i = 0; i < size; i++)
        {
            Node* front = levDeq.front();
            levDeq.pop_front();

            if(front->left != nullptr) levDeq.push_back(front->left);
            if(front->right != nullptr) levDeq.push_back(front->right);
        }
        
        level++;
    }
}

void Tree::printLeftViewOfTree(Node* root)
{
    if(root == nullptr) return;
    std::queue<Node*> travQ;
    travQ.push(root);
    
    while(!travQ.empty())
    {
        int travQSize = travQ.size();
        for (int i = 0; i < travQSize; i++)
        {
            Node* front = travQ.front();
            travQ.pop();

            if(i == 0) std::cout << front->data << " ";
            if(front->left != nullptr) travQ.push(front->left);
            if(front->right != nullptr) travQ.push(front->right);
        }
    }
}

bool Tree::childrenSumProperty(Node* root)
{
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;

    if(root->left == nullptr && root->data == root->right->data && childrenSumProperty(root->right)) return true;
    else if(root->right == nullptr && root->data == root->left->data && childrenSumProperty(root->left)) return true;
    else if(root->left != nullptr && root->right !=nullptr && root->data == (root->left->data + root->right->data) && childrenSumProperty(root->left) && childrenSumProperty(root->right)) return true;
    else return false;
}

int Tree::heightBalancedTree(Node* root)
{
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;

    if(root->left == nullptr && root->right != nullptr) return (-1 + heightBalancedTree(root->right));
    else if(root->right == nullptr && root->left != nullptr) return (1 + heightBalancedTree(root->left));
    else return (heightBalancedTree(root->left) - heightBalancedTree(root->right));
}

Node* Tree::buildTreeFromInOrderPreOrder(std::vector<int>& preorder, std::vector<int>& inorder, int rootNodeId)
{
    if(inorder.empty()) return nullptr;

    int rootNode = preorder[rootNodeId];

    std::vector<int> leftNodes, rightNodes;
    int inorderNodePos{0};
    for (int i = 0; i < inorder.size(); i++)
    {
        if(inorder[i] != rootNode) leftNodes.push_back(inorder[i]);
        else 
        {
            inorderNodePos = i;
            break;
        }
    }
    for (int i = inorderNodePos+1; i < inorder.size(); i++)
        rightNodes.push_back(inorder[i]);

    Node* root = new Node(rootNode);
    if(leftNodes.empty())
        root->left = buildTreeFromInOrderPreOrder(preorder, leftNodes, rootNodeId);
    else
        root->left = buildTreeFromInOrderPreOrder(preorder, leftNodes, ++rootNodeId);

    if(rightNodes.empty())
        root->right = buildTreeFromInOrderPreOrder(preorder, rightNodes, rootNodeId);
    else
        root->right = buildTreeFromInOrderPreOrder(preorder, rightNodes, ++rootNodeId);

    return root; 
}

int main(int argc, char const *argv[])
{
    std::cout << "Building Tree; Insert -1 at anypoint of time if you don't want to continue that direction" << std::endl;
    int n; std::cin >> n;
    Node* root = new Node(n);

    Tree tree;
    tree.buildTree(root);

    std::cout << "Printing tree : By default the inorder traversal" << std::endl;
    tree.printTree(root);
    std::cout << std::endl;

    // std::cout << "Printing tree : Preorder traversal" << std::endl;
    // tree.preTraversal(root);
    // std::cout << std::endl;

    // std::cout << "Printing tree : Postorder traversal" << std::endl;
    // tree.postTraversal(root);
    // std::cout << std::endl;

    // std::cout << "Tree operations : Tree height: " << std::endl;
    // std::cout << tree.getTreeHeight(root) << std::endl;

    // std::cout << "Printing tree nodes : All nodes which are at a distance 2 from node " << std::endl;
    // tree.printNodeAtDistanceK(root, 2, 0);
    // std::cout << std::endl;

    // std::cout << "Printing tree : Level order traversal" << std::endl;
    // tree.levelOrderTraversal(root);
    // std::cout << std::endl;

    std::cout << "Printing tree : Spiral traversal" << std::endl;
    tree.spiralTraversal(root);
    std::cout << std::endl;

    // std::cout << "Printing tree : Level order traversal line by line" << std::endl;
    // tree.levelOrderTraversalLineByLine(root);

    // std::cout << "Tree operations : Tree size: " << std::endl;
    // std::cout << tree.sizeOfTree(root) << std::endl;

    // std::cout << "Tree operations : Maximum value in the tree: " << std::endl;
    // std::cout << tree.maximumValueInTree(root) << std::endl;

    // std::cout << "Printing tree : Left view of tree" << std::endl;
    // tree.printLeftViewOfTree(root);
    // std::cout << std::endl;

    // std::cout << "Tree operations : Find if tree follows children sum property: " << std::endl;
    // if(tree.childrenSumProperty(root))
    //     std::cout << "Tree follows children sum property" << std::endl;
    // else
    //     std::cout << "Tree doesn't follows children sum property" << std::endl;

    // std::cout << "Tree operations : Find if tree height balanced or not: " << std::endl;
    // if(std::abs(tree.heightBalancedTree(root) > 1))
    //     std::cout << "Tree is not height balanced" << std::endl;
    // else
    //     std::cout << "Tree is height balanced" << std::endl;

    // Tree tree;

    // std::vector<int> inOrder({40, 20, 50, 10, 30, 80, 70, 90});
    // std::vector<int> preOrder({10, 20, 40, 50, 30, 70, 80, 90});
    // Node* root = tree.buildTreeFromInOrderPreOrder(preOrder, inOrder, 0);

    // tree.printTree(root);
    // std::cout << std::endl;

    return 0;
}
