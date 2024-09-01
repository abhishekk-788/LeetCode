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
    int sum = 0;
    void F(TreeNode* root, int flag) {
        if(root == NULL) return;
        if(flag == 1) 
        {
            if(root->left) sum += root->left->val;
            if(root->right) sum += root->right->val;
            
            flag = 0;
        }
        
        if(root->val % 2 == 0) flag = 1;
        
        F(root->left, flag);
        F(root->right, flag);
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        sum = 0;
        F(root, 0);    
        
        return sum;
    }
};