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
    
    long long p = 0, mod = 1000000007;
    
    int S(TreeNode* root) 
    {
        if(root == NULL) return 0;    
        return root->val + S(root->left) + S(root->right);
    }
    
    int F(TreeNode *root, int sum)
    {
        if(root == NULL) return 0;
        
        long long l = F(root->left, sum);
        long long r = F(root->right, sum);
        
        long long ans= max(l * (sum-l), r * (sum-r));
        p = max(p, ans);
        
        return l + r + root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        int sum = S(root);
        p = 0;
        
        F(root, sum);
        
        return p % mod;
    }
};