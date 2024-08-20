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
    string F(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return "(" + to_string(root->val) + ")";
        
        string str = "(" + to_string(root->val);
        if(root->left)
            str += F(root->left);
        else str += "()";
        
        if(root->right)
            str += F(root->right);
        
        str += ")";
        return str;
            
    }
    string tree2str(TreeNode* root) {
        string ans = F(root);
        ans = ans.substr(1,ans.length()-2);
        
        return ans;
    }
};