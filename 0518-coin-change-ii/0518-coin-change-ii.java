class Solution {
    public int change(int amount, int[] coins) {
        Arrays.sort(coins);
        int n = coins.length;

        long[][] dp = new long[n+1][amount+1];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= amount; j++)
                dp[i][j] = -1;

        long ans = F(coins, n, amount, dp);

        return (ans >= Integer.MAX_VALUE) ? -1: (int)ans;
    }
    
    long F(int[] coins, int n, int amount, long[][] dp) 
    {
        if(amount == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][amount] != -1) return dp[n][amount];

        if(coins[n-1] <= amount) {
            return dp[n][amount] = F(coins, n, amount - coins[n-1], dp) + F(coins, n-1, amount, dp);
        }
        return dp[n][amount] = F(coins, n-1, amount, dp);
    }
}