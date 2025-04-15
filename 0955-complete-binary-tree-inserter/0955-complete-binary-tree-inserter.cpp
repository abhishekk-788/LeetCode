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
class CBTInserter {
public:
    TreeNode *root = NULL;
    CBTInserter(TreeNode* r) {
        root = r;
    }
    
    int insert(int val) 
    {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode *curr;
        while(!q.empty()) 
        {
            curr = q.front();
            q.pop();

            if(curr->left == NULL) 
            {
                TreeNode *newNode = new TreeNode(val);
                curr->left = newNode;
                break;
            }
            if(curr->right == NULL) 
            {
                TreeNode *newNode = new TreeNode(val);
                curr->right = newNode;
                break;
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        return curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */