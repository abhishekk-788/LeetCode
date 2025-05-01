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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<TreeNode*> heads;
        queue<TreeNode*> q;

        unordered_map<int, int> hash;
        for(auto ele: to_delete) {
            hash[ele]++;
        }

        q.push(root);
        if(hash.count(root->val) == 0) {
            heads.push_back(root);
        }

        while(!q.empty())
        {
            TreeNode *f = q.front();
            q.pop();

            if(f->left) 
            {
                TreeNode *lft = f->left;
                q.push(lft);

                if(hash.count(lft->val)) f->left = NULL;
            } 
            if(f->right) {
                
                TreeNode *rght = f->right;
                q.push(rght);

                if(hash.count(rght->val)) f->right = NULL;
            } 

            if(hash.count(f->val) == 1) {
                if(f->left) {
                    heads.push_back(f->left);
                }
                if(f->right) {
                    heads.push_back(f->right);
                }
            }
        }
        return heads;
    }
};