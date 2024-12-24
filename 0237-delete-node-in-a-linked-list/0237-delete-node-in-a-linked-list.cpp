/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int nodeVal = node->val;
        ListNode *prev = NULL;
        
        while(node->next != NULL) {
            ListNode *nxt = node->next;
            node->val = nxt->val;
            
            prev = node;
            node = node->next;
        }
        
        prev->next = NULL;
    }
};