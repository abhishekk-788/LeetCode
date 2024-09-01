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
    TreeNode *MIN(TreeNode *root)
    {
        while(root->left != NULL) { 
            root = root->left;
        }
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL) return root; 
        
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        
        else
        {
            if(root->left == NULL && root->right == NULL) {
                delete (root);
                return NULL;
            }
            
            else if(root->left == NULL) {
                TreeNode *ptr = root;
                root = root->right;
                delete (ptr);
            }
            
            else if(root->right == NULL) {
                TreeNode *ptr = root;
                root = root->left;
                delete (ptr);
            }
            
            else
            {
                TreeNode *ptr = MIN(root->right);
                root->val = ptr->val;
                
                root->right = deleteNode(root->right, ptr->val);
            }
        }
        
        return root;
    }
};