#include <iostream>

struct Node
{
    int key;
    Node* left{nullptr};
    Node* right{nullptr};
    int height{1};

    Node(int val)
    {
        key = val;
    }
};

int height(Node* node)
{
    if(node == nullptr) return 0;
    else return node->height;
}

int balanceFactor(Node* node)
{
    if(node == nullptr) return 0;
    else return (height(node->left) - height(node->right));
}

Node* rightRotate(Node* y)
{
    // Define x, y, T1, T2, T3
    Node* x = y->left;
    Node* T3 = y->right;
    Node* T1 = x->left;
    Node* T2 = x->right;

    // Reaarange x, y, T1, T2 and T3 for right rotation
    x->left = T1;
    y->left = T2;
    y->right = T3;
    x->right = y;

    // Update height of x and y;
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return x;
}

Node* leftRotate(Node* y)
{
    // Define x, y, T1, T2, T3
    Node* T1 = y->left;
    Node* x = y->right;
    Node* T2 = x->left;
    Node* T3 = x->right;

    // Reaarange x, y, T1, T2 and T3 for left rotation
    x->right = T3;
    y->left = T1;
    y->right = T2;
    x->left = y;

    // Update height of x and y;
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return x;
}

Node* insert(Node* root, int key)
{
    // 1. perform normal BST
    if(root == nullptr)
        return new Node(key);
    else if(root->key > key)
        root->left = insert(root->left, key);
    else if(root->key < key)
        root->right = insert(root->right, key);
    else
        return root;

    // 2. Update height of current node
    root->height = 1 + std::max(height(root->left), height(root->right));

    // 3. check balance of current node
    int balance = balanceFactor(root);

    // 4. rebalance the node
    // left-left case
    if(balance > 1 && key < root->left->key)
        return rightRotate(root->left);

    // right-right case
    if(balance < -1 &&key > root->right->key)
        return leftRotate(root->right);

    // left-right case
    if(balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right-left case
    if(balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // if nothing change return root
    return root;
}

Node* deleteNode(Node* root, int key)
{
    // 1. Perform normal BST deletion
    if(root == nullptr) return root;
    else if(key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete(root); root = nullptr; return root;
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            Node* tmp = root->left;
            delete(root); root = nullptr; return tmp;
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            Node* tmp = root->right;
            delete(root); root = nullptr; return tmp;
        }
        else
        {
            Node* tmp = root->left;
            tmp->right = root->right;
            delete(root); root = nullptr; return tmp;
        }
    }

    // 2. Update height of current node (root)
    root->height = 1 + std::max(height(root->left), height(root->right));

    // 3. get balance factor
    int balance = balanceFactor(root);

    // 4. Do rotations based on different cases
    // 4.1 left-left case
    if(balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // 4.2 right-right case
    else if(balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // 4.3 left-right case
    else if(balance > 1 && balanceFactor(root->right) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 4.4 right-left case
    else if(balance < 1 && balanceFactor(root->left) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printAVLTree(Node* root)
{
    if(root != nullptr)
    {
        printAVLTree(root->left);
        std::cout << root->key << " ";
        printAVLTree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    Node *root = nullptr; 
  
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
  
    /* The constructed AVL Tree would be 
         9 
        / \ 
       1  10 
      / \   \ 
     0   5  11 
    /   / \ 
  -1   2   6 
    */
  
    std::cout << "Constructed AVL tree:" << std::endl;
    printAVLTree(root); 
    std::cout << std::endl;
  
    root = deleteNode(root, 10); 
  
    /* The AVL Tree after deletion of 10 
         5 
        / \ 
       1    9 
      / \  / \ 
     0   2 6  11 
    /
   -1
    */
  
    std::cout << "AVL tree after deleting 10:" << std::endl;
    printAVLTree(root); 
    std::cout << std::endl;
  
    return 0; 
}
