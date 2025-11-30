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
            // 7 6 8 5
            // 5 6 7 8
            int n = list.size();
            List<Integer> sortedList = new ArrayList<>(list);
            Collections.sort(sortedList);

            HashMap<Integer, Integer> pos = new HashMap<>();
            for (int i = 0; i < n; i++){
                pos.put(list.get(i), i);
            }
            
            for(int i = 0; i < n; i++) 
            {
                int want = sortedList.get(i);
                if (list.get(i) != want) 
                {
                    ans++;
                    int curVal = list.get(i);
                    int j = pos.get(want);

                    list.set(j, curVal);
                    list.set(i, want);

                    pos.put(curVal, j);
                    pos.put(want, i);
                }
            }
        }
        return ans;
    }
}