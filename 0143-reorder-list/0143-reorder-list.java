/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        int cnt = 0;
        Stack<ListNode> stack = new Stack<>();
        ListNode ptr = head;
        while(ptr != null) {
            cnt++;
            stack.push(ptr);
            ptr = ptr.next;
        }
        ListNode newHead = head;
        for(int i = 0; i < cnt/2; i++ ) 
        {
            ListNode nxt = newHead.next;
            ListNode top = stack.pop();
            newHead.next = top;
            top.next = nxt;
            newHead = nxt;
        }
        newHead.next = null;
    }
}