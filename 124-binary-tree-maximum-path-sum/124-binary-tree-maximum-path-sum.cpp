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
class Solution {
public:
    int mx = -1000000007;
    int F(TreeNode* root)
    {
        if(root == NULL) return -1000000007;
        
        int l = F(root->left);
        int r = F(root->right);
        
        int d = max(l, r);
        int s = max(root->val, root->val + d);
        
        mx = max(mx, max(s, root->val + l + r));
        return s;
    }
    int maxPathSum(TreeNode* root) 
    {
        F(root);
        return mx;
    }
};