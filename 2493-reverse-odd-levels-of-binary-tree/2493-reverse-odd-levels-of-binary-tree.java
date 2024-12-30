/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        int level = 0;
        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);
        q.add(null);

        while(q.size() > 1)
        {
            Deque<TreeNode> dq = new ArrayDeque<>();
            while(q.peek() != null) {

                TreeNode front = q.poll();
                dq.addLast(front);
                
                if(front.left != null) q.add(front.left);
                if(front.right != null) q.add(front.right);
            }
            
            if(level == 0) {
                while(!dq.isEmpty()) {
                    dq.poll();
                }
            }

            while(!dq.isEmpty() && level > 0) {
                TreeNode front = dq.pollFirst();
                TreeNode back = dq.pollLast();
                
                if(level % 2 == 1) {
                    int temp = front.val;
                    front.val = back.val;
                    back.val = temp;
                }
            }

            q.poll();
            q.add(null);
            
            level++;
        }
        
        return root;
    }
}