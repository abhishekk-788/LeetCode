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
    unordered_map<long, long> hash;
    int ans = 0;
    
    void F(TreeNode* root, long targetSum, long sum)
    {
        if(root == NULL) return;
        long x = sum + root->val - targetSum;
        
        if(hash.count(x) == 1) {
            ans += hash[x];
        }

        hash[sum + root->val]++;

        F(root->left, targetSum, sum + root->val);
        F(root->right, targetSum, sum + root->val);

        hash[sum + root->val]--;

    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL) return 0;
        hash[0]++;

        F(root, targetSum, 0);

        return ans;
    }
};

/*



*/