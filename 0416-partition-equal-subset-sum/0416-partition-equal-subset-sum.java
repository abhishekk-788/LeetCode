class Solution {
    public int F(int[] nums, int s, int n, int[][] dp) {
        if (s == 0 && n == 0) return 1;
        if (s < 0 || n == 0) return 0;

        if (dp[n][s] != -1) return dp[n][s];

        if (nums[n-1] <= s) {
            dp[n][s] = (F(nums, s - nums[n-1], n-1, dp) == 1 || F(nums, s, n-1, dp) == 1) ? 1 : 0;
        } else {
            dp[n][s] = F(nums, s, n-1, dp);
        }
        return dp[s][n];
    }

    public boolean canPartition(int[] nums) {
        int n = nums.length, s = 0;
        for (int ele : nums) {
            s += ele;
        }

        if (s % 2 == 1) return false;
        s = s / 2;

        int[][] dp = new int[n+1][s+1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int j = 1; j <= s; j++) {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= s; j++) 
            {
                if(nums[i-1] <= j) {
                    dp[i][j] = (dp[i-1][j-nums[i-1]] == 1 || dp[i-1][j] == 1) ? 1: 0;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][s] == 1;
    }
}

/*

1, 5, 5, 11


*/