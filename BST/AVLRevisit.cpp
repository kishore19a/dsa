#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
    int height{1};

    Node() : left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return root->height;
}

int balanceFactor(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return (height(root->left) - height(root->right));
}

Node* rightRotate(Node* y)
{
    // initial state
    Node* x = y->left;
    Node* T1 = x->left;
    Node* T2 = x->right;
    Node* T3 = y->right;

    // final state
    y->left = T2;
    x->right = y;

    // update heights of re-arranged nodes
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return x;
}

Node* leftRotate(Node* y)
{
    // initial state
    Node* x = y->right;
    Node* T1 = y->left;
    Node* T2 = x->left;
    Node* T3 = x->right;

    // final state
    y->right = T2;
    x->left = y;

    // update heights of re-arranged nodes
    x->height = 1 + std::max(height(x->left), height(x->right));
    y->height = 1 + std::max(height(y->left), height(y->right));

    return x;
}

Node* avlInsert(Node* root, int val)
{
    // Step 1: Normal BST insert
    if(root == nullptr)
        return (new Node(val));

    if(root->data > val)
        root->left = avlInsert(root->left, val);
    else if(root->data < val)
        root->right = avlInsert(root->right, val);
    else
        return root;        
    
    // Step 2: Calculate height of current node
    root->height = 1 + std::max(height(root->left), height(root->right));

    // Step 3: Calculate balance factor
    int balance = balanceFactor(root);

    // Step 4: Identify which rotation to do
    // left left case
    if(balance > 1 && root->left->data > val)
        return rightRotate(root);

    // left right case
    if(balance > 1 && root->left->data < val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right left case
    if(balance < -1 && root->right->data > val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // right right case
    if(balance < -1 && root->right->data < val)
        return leftRotate(root);


    // Step 5: return unchanged node;
    return root;    
}

void preOrder(Node *root)
{
    if(root != nullptr)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* getSuccessor(Node* root)
{
    Node* curr = root->right;
    while(curr != nullptr)
        curr = curr->left;
    
    return curr;
}

Node* avlDelete(Node* root, int val)
{
    // Step 1 : Normal BST delete
    if(root == nullptr)
        return nullptr;

    if(root->data > val)
        root->left = avlDelete(root->left, val);
    else if(root->data < val)
        root->right = avlDelete(root->right, val);
    else
    {
        // Case 1 : It is a leaf node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete(root);
            root = nullptr;
            return root;
        }
        // Case 2 : the node to be deleted has only left child
        else if (root->left != nullptr && root->right == nullptr)
        {
            Node* left = root->left;
            delete(root);
            root = nullptr;
            return left;
        }
        // Case 3 : the node to be deleted has only right child
        else if (root->left == nullptr && root->right != nullptr)
        {
            Node* right = root->right;
            delete(root);
            root = nullptr;
            return right;
        }
        // Case 4 : the node to be deleted has both children
        else
        {
            Node* succ = getSuccessor(root);
            root->data = succ->data;
            root->right = avlDelete(root->right, succ->data);

            return root;
        }
    }

    // Step 2 : Update height of this ancestor
    root->height = 1 + std::max(height(root->left), height(root->right));

    // Step 3 : Find balance factor
    int balance = balanceFactor(root);

    // Step 4 : Balance the tree if unbalanced
    // left left case
    if(balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
    
    // left right case
    if(balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right right case
    if(balance < -1 && balanceFactor(root->right) < 0)
        return leftRotate(root);

    // right left case
    if(balance < -1 && balanceFactor(root->right) >= 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
 

int main(int argc, char const *argv[])
{
    Node* root{nullptr};

    root = avlInsert(root, 9);
    root = avlInsert(root, 5);
    root = avlInsert(root, 10);
    root = avlInsert(root, 0);
    root = avlInsert(root, 6);
    root = avlInsert(root, 11);
    root = avlInsert(root, -1);
    root = avlInsert(root, 1);
    root = avlInsert(root, 2);

    preOrder(root);
    std::cout << std::endl;

    // root = avlDelete(root, 10);

    // preOrder(root);
    // std::cout << std::endl;

    return 0;
}
