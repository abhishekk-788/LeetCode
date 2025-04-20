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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL) return {};

        // level order traversal
        queue<TreeNode*> q;
        vector<int> rv;

        q.push(root);
        q.push(NULL);

        rv.push_back(root->val);

        while(q.size() > 1) 
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) {
                curr = q.front();
                q.pop();

                if(curr != NULL) rv.push_back(curr->val);
                q.push(NULL);
            }

            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);
        }

        return rv;
    }
};