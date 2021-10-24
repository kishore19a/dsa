#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val, Node* l, Node* r) : data(val), left(l), right(r) {}
};

Node* buildTree(int val)
{
    if(val == -1)
        return nullptr;

    Node* root{nullptr};
    if(root == nullptr)
        root = new Node(val);

    int n;
    // std::cout << "Building left subtree of - { " << val << " }; Enter -1 to stop " << std::endl;
    std::cin >> n;
    root->left = buildTree(n);

    // std::cout << "Building right subtree of - { " << val << " }; Enter -1 to stop " << std::endl;
    std::cin >> n;
    root->right = buildTree(n);

    return root;
}

void inorderTrav(Node* root)
{
    if(root != nullptr)
    {
        inorderTrav(root->left);
        std::cout << root->data << ", ";
        inorderTrav(root->right);
    }
}

void inorderTravWithoutRecc(Node* root)
{
    if(root == nullptr) return;

    std::stack<Node*> inStack;
    Node* curr{root};

    while(curr != nullptr || !inStack.empty())
    {
        while(curr != nullptr)
        {
            inStack.push(curr);
            curr = curr->left;
        }
        
        curr = inStack.top();
        inStack.pop();

        std::cout << curr->data << ", ";

        if(curr != nullptr) curr = curr->right;
    }
}

void preorderTrav(Node* root)
{
    if(root != nullptr)
    {
        std::cout << root->data << ", ";
        preorderTrav(root->left);
        preorderTrav(root->right);
    }
}

void preOrderTravWithoutRecc(Node* root)
{
    if(root == nullptr) return;

    std::stack<Node*> preStack;
    Node* curr{root};

    while (curr != nullptr || !preStack.empty())
    {
        while(curr != nullptr)
        {
            std::cout << curr->data << ", ";
            preStack.push(curr);
            curr = curr->left;
        }

        curr = preStack.top();
        preStack.pop();

        if(curr != nullptr) curr = curr->right;
    }
    
}

void postorderTrav(Node* root)
{
    if(root != nullptr)
    {
        postorderTrav(root->left);
        postorderTrav(root->right);
        std::cout << root->data << ", ";
    }
}

// void postOrderTravWithoutRecc(Node* root)
// {
//     if(root == nullptr) return;

//     std::stack<Node*> postStack;
//     Node* curr{root};

//     while (curr != nullptr || !postStack.empty())
//     {
//         while(curr != nullptr)
//         {
//             postStack.push(curr);
//             curr = curr->left;
//         }

//         curr = postStack.top();
//         postStack.pop();

//         if(curr->right == nullptr) std::cout << curr->data << ", ";
//         else 
//         {
//             postStack.push(curr);
//             curr = curr->right;
//         }
//     }
    
// }

vector<int> leftView(Node *root)
{
   std::vector<int> leftViewVec;
   if(root == nullptr) return leftViewVec;
   
   std::queue<Node*> trav;
   trav.push(root);
   
   while(!trav.empty())
   {
       int size = trav.size();
       leftViewVec.push_back(trav.front()->data);
       
       for(int i = 0; i < size; i++)
       {
           Node* front = trav.front();
           trav.pop();
           
           if(front->left != nullptr) trav.push(front->left);
           if(front->right != nullptr) trav.push(front->right);
       }
   }
   
   return leftViewVec;
}

void fillHValue(Node* root, std::map<int, int>& hValMap, int hVal)
{
    if(root != nullptr)
    {
        hValMap[hVal] = root->data;
        std::cout << "havl of " << root->data << " = " << hVal << std::endl;
        fillHValue(root->left, hValMap, hVal-1);
        fillHValue(root->right, hValMap, hVal+1);
    }
}
    
vector<int> bottomView(Node *root) 
{
    std::map<int, int> hValMap;
    std::vector<int> res;
    int hVal{0};
    
    fillHValue(root, hValMap, hVal);
    
    for(auto x : hValMap)
        res.push_back(x.second);
        
    return res;
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

        std::cout << front->data << ", ";

        if(front->left != nullptr) travQ.push(front->left);
        if(front->right != nullptr) travQ.push(front->right);
    }    
}

void setNeighbours(Node* root, std::unordered_map<int, std::vector<int>>& neighbours, std::unordered_map<int, bool>& burnt)
{
    if(root != nullptr)
    {
        burnt[root->data] = false;
        if(root->left != nullptr)
        {
            neighbours[root->data].push_back(root->left->data);
            neighbours[root->left->data].push_back(root->data);
        }
        if(root->right != nullptr)
        {
            neighbours[root->data].push_back(root->right->data);
            neighbours[root->right->data].push_back(root->data);
        }

        setNeighbours(root->left, neighbours, burnt);
        setNeighbours(root->right, neighbours, burnt);
    }
}

int burnTree(Node* root, int targetNode)
{
    if(root == nullptr) return 0;

    std::unordered_map<int, std::vector<int>> neighbours;
    std::unordered_map<int, bool> burnt;
    setNeighbours(root, neighbours, burnt);

    std::queue<int> burnTrav;
    burnTrav.push(targetNode);

    int time{0};

    while(!burnTrav.empty())
    {
        int size = burnTrav.size();
        for(int i = 0; i < size; i++)
        {
            int front = burnTrav.front();
            burnTrav.pop();

            burnt[front] = true;

            for(auto& neb : neighbours[front])
            {
                if(!burnt[neb])
                    burnTrav.push(neb);
            }
        }
        time++;
    }

    return time;
}

int heightOfTree(Node* root)
{
    if(root == nullptr)
        return 0;
    else
        return 1 + std::max(heightOfTree(root->left), heightOfTree(root->right));
}

int main(int argc, char const *argv[])
{
    std::cout << "--------------- Building tree first --------------------" << std::endl;

    int n;
    // std::cout << "Enter root of the tree; Enter -1 to stop" << std::endl;
    std::cin >> n;

    Node* root = buildTree(n);

    std::cout << "--------------- Traversing tree - inorder --------------------" << std::endl;
    inorderTrav(root);
    std::cout << std::endl;

    std::cout << "--------------- Traversing tree - inorder without recurrsion--------------------" << std::endl;
    inorderTravWithoutRecc(root);
    std::cout << std::endl;

    std::cout << "--------------- Traversing tree - preorder --------------------" << std::endl;
    preorderTrav(root);
    std::cout << std::endl;

    std::cout << "--------------- Traversing tree - preorder without recurrsion --------------------" << std::endl;
    preOrderTravWithoutRecc(root);
    std::cout << std::endl;

    std::cout << "--------------- Traversing tree - postorder --------------------" << std::endl;
    postorderTrav(root);
    std::cout << std::endl;

    std::cout << "--------------- Bottom view of tree --------------------" << std::endl;
    std::vector<int> bottomViewOfTree = bottomView(root);
    for(auto x : bottomViewOfTree)
        std::cout << x << ", ";
    std::cout << std::endl;

    std::cout << "--------------- Traversing tree - level order --------------------" << std::endl;
    levelOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "--------------- Height of tree --------------------" << std::endl;
    std::cout << "Height of tree = " << heightOfTree(root) << std::endl;

    std::cout << "--------------- burn tree --------------------" << std::endl;
    int time = burnTree(root, 4);
    std::cout << "Time = " << time << std::endl;

    return 0;
}
