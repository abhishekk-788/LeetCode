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
    int ans = -1, cnt;
    void F(TreeNode* root) {
        if(root == NULL) return;
        
        F(root->left);

        if(cnt == 1 && ans == -1) {
            ans = root->val;
            return;
        }
        else cnt--;

        F(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        F(root);

        return ans;
    }
};