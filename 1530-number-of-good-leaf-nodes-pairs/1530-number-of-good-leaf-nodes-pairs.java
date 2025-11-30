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
    int ans = 0;
    int dist = 0;
    
    public int[] dfs(TreeNode root) {
        if(root == null) {
            int[] arr = new int[dist + 1];
            return arr;
        }
        if(root.left == null && root.right == null) {
           int[] arr = new int[dist + 1];
           arr[1] = 1;
           return arr;
        }

        int[] left = dfs(root.left);
        int[] right = dfs(root.right);

        for (int i = 1; i <= dist; ++i) 
        {
            if (left[i] == 0) continue;
            for (int j = 1; j <= dist; ++j) 
            {
                if (right[j] == 0) continue;
                if (i + j <= dist) ans += left[i] * right[j];
            }
        }

        int[] arr = new int[dist + 1];
        for (int d = 1; d < dist; ++d) 
        {
            arr[d + 1] += left[d];
            arr[d + 1] += right[d];
        }
        return arr;
    }
    public int countPairs(TreeNode root, int distance) {
        dist = distance;
        dfs(root);
        return ans;
    }
}