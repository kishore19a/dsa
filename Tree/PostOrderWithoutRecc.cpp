#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* A) {
    std::vector<int> res;
    std::vector<TreeNode*> resNode;
    if(A == nullptr) return res;

    TreeNode* curr{A};
    std::stack<TreeNode*> travStack;

    while(curr != nullptr || !travStack.empty())
    {
        while(curr != nullptr)
        {
            travStack.push(curr);
            curr = curr->left;
        }

        TreeNode* top = travStack.top();

        if( (top->left == nullptr && top->right == nullptr) ||
            (top->left != nullptr && top->right == nullptr && top->left == resNode.back()) ||
            (top->left == nullptr && top->right != nullptr && top->right == resNode.back()) ||
            (top->left != nullptr && top->right != nullptr && (top->right == resNode.back()))
        )
        {
            travStack.pop();
            res.push_back(top->val);
            resNode.push_back(top);
        }

        curr = top->right;
    }

    return res;
}
