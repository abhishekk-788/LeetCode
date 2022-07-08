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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>> vec(m, vector<int> (n, -1));
        
        int l = 0, r = n-1, t = 0, b = m-1;
        while(head != NULL)
        {
            for(int i = l; i <= r && head != NULL; i++) 
            {
                vec[t][i] = head->val;
                head = head->next;
                
                // cout << vec[t][i] << "\n";
            }
            t++;
            for(int i = t; i <= b && head != NULL; i++) 
            {
                vec[i][r] = head->val;
                head = head->next;
                
                // cout << vec[i][r] << "\n";
            }
            r--;
            for(int i = r; i >= l && head != NULL; i--) 
            {
                vec[b][i] = head->val;
                head = head->next;
                
                // cout << vec[b][i] << "\n";
            }
            b--;
            for(int i = b; i >= t && head != NULL; i--) 
            {
                vec[i][l] = head->val;
                head = head->next;
                
                // cout << vec[i][l] << "\n";
            }
            l++;
        }
        
        return vec;
    }
};