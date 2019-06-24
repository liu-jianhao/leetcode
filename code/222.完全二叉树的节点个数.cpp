/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if(left == right)
        {
            // 1(根节点) + (1 << left) - 1(左完全左子树节点数) + 右子树节点数
            return (1 << left) + countNodes(root->right);
        } 
        else
        {
            // 1(根节点) + (1 << rd) - 1(右完全右子树节点数) + 左子树节点数量
            return (1 << right) + countNodes(root->left);
        }
    }

    int getDepth(TreeNode* root)
    {
        int depth = 0;
        while(root)
        {
            ++depth;
            root = root->left;
        }
        return depth;
    }
};