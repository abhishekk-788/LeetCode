class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int[] dp = new int[n]; 
        int[] cnt = new int[n];
        int maxLength = 1, result = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            cnt[i] = 1;
        }

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[i] > nums[j]) 
                {
                    if (dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j]; 
                    } else if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            maxLength = Math.max(maxLength, dp[i]);
        }

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                result += cnt[i];
            }
        }

        return result;
    }
}
