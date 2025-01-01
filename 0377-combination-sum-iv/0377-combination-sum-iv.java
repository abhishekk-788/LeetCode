class Solution {
    int F(int[] nums, int n, int target, int[][] dp) 
    {
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += F(nums, n, target-nums[i-1], dp);
        }
        return dp[n][target] = ans;
    }
    public int combinationSum4(int[] nums, int target) 
    {
        int n = nums.length;
        int[][] dp = new int[n+1][target+1];

        for(int i = 0; i <= n; i++) 
            for(int j = 0; j <= target; j++)
                dp[i][j] = -1;

        return F(nums, n, target, dp);    
    }
}