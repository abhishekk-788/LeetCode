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
    unordered_map<int, int> mp;
    bool Search(TreeNode *root, int t)
    {
        if(!root) return false;

        bool l = Search(root->left,t);

        if(mp.count(t - root->val) == 1)
            return true;
        
        mp[root->val]++;

        bool r = Search(root->right,t); 
        return (l || r);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;

        return Search(root,k);
    }
};