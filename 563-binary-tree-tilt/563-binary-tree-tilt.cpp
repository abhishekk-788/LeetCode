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
    int s = 0;
    int F(TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int l = F(root->left);
        int r = F(root->right);
        
        s += abs(l-r);
        
        return l + r + root->val;
    }
    int findTilt(TreeNode* root) 
    {
        s = 0;
        F(root);
        
        return s;
    }
};

/*




*/