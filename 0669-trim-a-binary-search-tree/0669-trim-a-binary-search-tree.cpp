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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        if(root->val <= high && root->val >= low) {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        else if(root->val >= high) {
            root->left = trimBST(root->left, low, high);
            if(root->left == NULL) return NULL;
            else return root->left;
        }
        else if(root->val <= low) {
            root->right = trimBST(root->right, low, high);
            if(root->right == NULL) return NULL;
            else return root->right;
        }
        return root;
    }
};

/*

*/