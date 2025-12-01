class Solution {
    public int longestConsecutive(int[] nums) 
    {
        Set<Integer> hash = new HashSet<>();
        int n = nums.length;

        for(int i = 0; i < n; i++) {
            hash.add(nums[i]);
        }
        int ans = 0;
        for(int x: hash) {
            if(hash.contains(x-1)) {
                continue;
            }
            int len = 1;
            while(hash.contains(x + 1)) {
                x = x + 1;
                len++;
            }
            ans = Math.max(ans, len);
        }
        return ans;
    }
}