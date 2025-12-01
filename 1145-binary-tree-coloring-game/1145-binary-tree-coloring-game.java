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
    TreeNode redNode;
    public void find(TreeNode root, int x)
    {
        if(root == null) return;
        if(root.val == x) {
            redNode = root;
        }
        find(root.left, x);
        find(root.right, x);
    }
    public int countChildNodes(TreeNode root) {
        if(root == null) return 0;
        if(root.left == null && root.right == null) return 1;

        return 1 + countChildNodes(root.left) + countChildNodes(root.right);
    }
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        find(root, x);
        
        int left = countChildNodes(redNode.left);
        int right = countChildNodes(redNode.right);

        int parent = n - (1 + left + right);

        return (left > n / 2) || (right > n / 2) || (parent > n / 2);
    }
}