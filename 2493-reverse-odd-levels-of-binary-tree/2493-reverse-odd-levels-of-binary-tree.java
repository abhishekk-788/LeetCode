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
        if (root == null) return root;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        int level = 0;

        while (!q.isEmpty()) 
        {
            int size = q.size();
            Deque<TreeNode> deque = new ArrayDeque<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                deque.addLast(node);

                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }

            if (level % 2 == 1) {
                while (deque.size() > 1) 
                {
                    TreeNode front = deque.pollFirst();
                    TreeNode back = deque.pollLast();

                    int temp = front.val;
                    front.val = back.val;
                    back.val = temp;
                }
            }

            level++;
        }

        return root;
    }
}