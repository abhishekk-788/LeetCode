/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL) return NULL;
        queue<Node*> q;

        q.push(root);
        q.push(NULL);

        while(q.size() > 1)
        {
            Node* curr = NULL;
            Node* ptr = q.front();

            while(ptr != NULL)
            {
                if(ptr->left) {
                    if(curr != NULL) {
                        curr->next = ptr->left;
                    }
                    curr = ptr->left;
                    q.push(ptr->left);
                }
                if(ptr->right) {
                    if(curr != NULL) {
                        curr->next = ptr->right;
                    }
                    curr = ptr->right;
                    q.push(ptr->right);
                }

                q.pop();
                
                if(q.front() == NULL) {
                    ptr->next = NULL;
                }
                ptr = q.front();
            }

            q.push(NULL);
            curr = NULL;

            if(ptr == NULL) {
                q.pop();
            }
        } 
        return root;
    }
};