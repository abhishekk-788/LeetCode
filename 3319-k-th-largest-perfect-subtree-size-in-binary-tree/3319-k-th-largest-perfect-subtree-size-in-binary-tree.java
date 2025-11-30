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
    private PriorityQueue<Integer> pq;
    private int K;

    private int dfs(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) {
            record(1);
            return 1;
        }

        int L = dfs(node.left);
        int R = dfs(node.right);

        if (L == R && L != 0) {
            int size = L + R + 1;
            record(size);
            return size;
        }
        return 0;
    }

    private void record(int size) 
    {
        if (K <= 0) return;
        if (pq.size() < K) {
            pq.offer(size);
        } else if (size > pq.peek()) {
            pq.poll();
            pq.offer(size);
        }
    }

    public int kthLargestPerfectSubtree(TreeNode root, int k) {
        if (root == null) return -1;
        if (k <= 0) return -1;

        this.K = k;
        this.pq = new PriorityQueue<>(k);

        dfs(root);

        if (pq.size() < k) return -1;
        return pq.peek();
    }
}