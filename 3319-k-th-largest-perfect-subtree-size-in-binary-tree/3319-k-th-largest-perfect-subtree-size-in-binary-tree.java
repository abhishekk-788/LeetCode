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
    List<Integer> list;
    public int F(TreeNode root)
    {
        if(root == null) return 0;
        if(root.left == null && root.right == null) 
        {
            System.out.println(root.val);
            list.add(1);
            return 1;
        }

        int l = F(root.left);
        int r = F(root.right);

        if(l == r && l != 0) {
            list.add(l + r + 1);
            return l + r + 1;
        }
        return 0;
    }
    public int kthLargestPerfectSubtree(TreeNode root, int k) 
    {
        list = new ArrayList<>();
        F(root); 

        Collections.sort(list, (a, b) -> b-a); 
        System.out.println(list); 
        return (k > list.size()) ? -1: list.get(k-1); 
    }
}