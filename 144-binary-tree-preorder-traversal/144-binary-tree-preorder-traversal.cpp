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
    void preorderTraversalHelper(TreeNode* root, vector<int> &res) 
    {
        if(root)
        {
            res.push_back(root -> val);           

            if(root -> left)
                preorderTraversalHelper(root -> left, res);

            if(root -> right)
                preorderTraversalHelper(root -> right, res);
        }

        return;
    }


    vector<int> preorderTraversal(TreeNode* root) 
    {   
        vector<int> res;
        preorderTraversalHelper(root, res) ;
        return res;
    }
};
