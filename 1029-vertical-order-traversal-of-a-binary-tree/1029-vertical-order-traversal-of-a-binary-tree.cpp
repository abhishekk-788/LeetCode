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
    map<int, vector<vector<int>>> G;
    void F(TreeNode* root, int row, int col) 
    {
        if(root == NULL) return;
        G[row].push_back({col, root->val});

        F(root->left, row-1, col+1);
        F(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        F(root, 0, 0);
        vector<vector<int>> vec;

        for(auto i: G) {
            sort(i.second.begin(), i.second.end());
            
            vector<int> v;
            for(auto j: i.second) {
                v.push_back(j[1]);
            }
            vec.push_back(v);
        }

        return vec;
    }
};