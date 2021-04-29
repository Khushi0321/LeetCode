/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode* root, int& depth)
    {
        if (root == nullptr)
        {
            depth = 0;
            return true;
        }
        
        int left_depth = 0;
        if (!isBalanced(root->left, left_depth))
        {
            return false;
        }
        
        int right_depth = 0;
        if (!isBalanced(root->right, right_depth))
        {
            return false;
        }
        
        depth = max(left_depth, right_depth) + 1;
        return (left_depth == right_depth || left_depth == right_depth + 1 || left_depth + 1 == right_depth);
    }
    
    bool isBalanced(TreeNode* root)
    {
        int depth = 0;
        return isBalanced(root, depth);
    }
};