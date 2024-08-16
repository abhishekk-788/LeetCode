/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(-101, head); 
        ListNode* pre_ptr = dummy;
        ListNode* ptr = head;
        
        while (ptr && ptr->next) 
        {
            if (ptr->val == ptr->next->val) 
            {
                int data = ptr->val;
                while (ptr && ptr->val == data) 
                {
                    ListNode* temp = ptr;
                    ptr = ptr->next;
                    delete temp;
                }
                pre_ptr->next = ptr;
            }
            else {
                pre_ptr = ptr;
                ptr = ptr->next;
            }
        }
        head = dummy->next;
        
        delete dummy;
        return head;
    }
};


/*

1 1 1 2 3

1 1 1 2 2 2 3 3 3 4

1 2 2 2 3 3 3


*/