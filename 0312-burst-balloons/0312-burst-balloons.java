class Solution {
    int F(int[] nums, int i, int j, int[][] dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mx = Integer.MIN_VALUE;
        for(int k = i; k <= j; k++)
        {
            int ans = nums[i-1] * nums[k] * nums[j+1];
            int value = F(nums, i, k-1, dp) + F(nums, k+1, j, dp);

            mx = Math.max(mx, ans + value);
        }

        return dp[i][j] = mx;
    }
    public int maxCoins(int[] nums) {
        int[] arr = new int[nums.length+2];
        int n = arr.length;
        
        arr[0] = arr[n-1] = 1;

        int[][] dp = new int[n+1][n+1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }

        for(int i = 1; i < n-1; i++) {
            arr[i] = nums[i-1];
        }
        
        return F(arr, 1, n-2, dp);
    }
}