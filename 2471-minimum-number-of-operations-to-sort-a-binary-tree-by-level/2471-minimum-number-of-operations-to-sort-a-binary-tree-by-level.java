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
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);

        int ans = 0;

        while(!q.isEmpty()) {
            int size = q.size();
            List<Integer> list = new ArrayList<>();
            while(size != 0)
            {
                TreeNode node = q.remove();
                list.add(node.val);

                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);

                size--;
            }

            int n = list.size();
            List<Integer> sortedList = new ArrayList<>(list);
            Collections.sort(sortedList);

            Integer[] idx = new Integer[n];
            for (int i = 0; i < n; i++) idx[i] = i;

            Arrays.sort(idx, Comparator.comparingInt(i -> list.get(i)));

            boolean[] visited = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (visited[i] || idx[i] == i) continue;
                int cycleSize = 0;
                int cur = i;
                while (!visited[cur]) {
                    visited[cur] = true;
                    cur = idx[cur];
                    cycleSize++;
                }
                if (cycleSize > 0) ans += cycleSize - 1;
            }
        }
        return ans;
    }
}