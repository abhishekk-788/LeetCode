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
    int ans = 0;
    void F(TreeNode* root, int dir, int cnt) {
        if(root == NULL) {
            ans = max(ans, cnt);
            return;
        }

        int leftCnt = (dir == 2) ? cnt + 1: 0;
        int rightCnt = (dir == 1) ? cnt + 1: 0;

        F(root->left, 2, rightCnt);
        F(root->right, 1, leftCnt);
    }
    int longestZigZag(TreeNode* root) 
    {
        F(root, 0, 0);   
        return ans; 
    }
};