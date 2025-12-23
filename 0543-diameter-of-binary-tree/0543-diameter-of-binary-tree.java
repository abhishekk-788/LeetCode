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
    public int mx = 0;
    public int F(TreeNode root)
    {
        if(root == null) return -1;
        int l = 1 + F(root.left);
        int r = 1 + F(root.right);

        mx = Math.max(mx, l + r);
        return Math.max(l, r);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        F(root);
        return mx;
    }
}