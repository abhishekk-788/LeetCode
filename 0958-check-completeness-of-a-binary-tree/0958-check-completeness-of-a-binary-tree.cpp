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
    bool isCompleteTree(TreeNode* root) 
    {
        if(root == NULL) return true;

        queue<TreeNode*> q;
        vector<int> tree;
        
        q.push(root);
        tree.push_back(root->val);
        
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            
            if(curr->left) {
                tree.push_back(curr->left->val);
                q.push(curr->left);
            }
            else tree.push_back(-1);
            
            if(curr->right) {
                tree.push_back(curr->right->val);
                q.push(curr->right);
            }
            else tree.push_back(-1);
            
        }
        
        for(int i = 0; i < tree.size()-1; i++) {
            if(tree[i] == -1 && tree[i+1] != -1) return false;
        }
        return true;
    }
};