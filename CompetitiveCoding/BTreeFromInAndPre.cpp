#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int& rootNodeId) {

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

    TreeNode* root = new TreeNode(rootNode);
    if(leftNodes.empty())
        root->left = buildTree(preorder, leftNodes, rootNodeId);
    else
        root->left = buildTree(preorder, leftNodes, ++rootNodeId);

    if(rightNodes.empty())
        root->right = buildTree(preorder, rightNodes, rootNodeId);
    else
        root->right = buildTree(preorder, rightNodes, ++rootNodeId);

    return root;   
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int startId{0};
    return buildTree(preorder, inorder, startId);
}

int preIndex{0};
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder, int startIndex, int endIndex) 
{
    if(endIndex < startIndex) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    int inIndex;
    for (int i = startIndex; i <= endIndex; i++)
    {
        if(inorder[i] == root->val)
        {
            inIndex = i;
            break;
        }
    }    

    
    root->left = buildTree(preorder, inorder, startIndex, inIndex-1);
    root->right = buildTree(preorder, inorder, inIndex+1, endIndex);

    return root;   
}

TreeNode* buildTreeEff(std::vector<int>& preorder, std::vector<int>& inorder)
{
    return buildTree(preorder, inorder, 0, inorder.size()-1);
}

void printTree(TreeNode* root)
{
    if(root != nullptr)
    {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> inOrder({40, 20, 50, 10, 30, 80, 70, 90});
    std::vector<int> preOrder({10, 20, 40, 50, 30, 70, 80, 90});

    TreeNode* root = buildTreeEff(preOrder, inOrder);

    printTree(root);
    std::cout << std::endl;

    return 0;
}

