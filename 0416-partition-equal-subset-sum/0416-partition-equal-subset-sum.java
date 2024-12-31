class Solution {
    public int F(int[] nums, int s, int n, int[][] dp) {
        if (s == 0 && n == 0) return 1;
        if (s < 0 || n == 0) return 0;

        if (dp[s][n] != -1) return dp[s][n];

        if (nums[n-1] <= s) {
            dp[s][n] = (F(nums, s - nums[n-1], n-1, dp) == 1 || F(nums, s, n-1, dp) == 1) ? 1 : 0;
        } else {
            dp[s][n] = F(nums, s, n-1, dp);
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
        int[][] dp = new int[s+1][n+1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return F(nums, s, n, dp) == 1;
    }
}

/*

1, 5, 5, 11


*/