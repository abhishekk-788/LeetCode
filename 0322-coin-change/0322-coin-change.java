class Solution {
    long F(int[] coins, int n, int amount, long[][] dp) 
    {
        if(amount == 0) return 0;
        if(n == 0) return Integer.MAX_VALUE;

        if(dp[n][amount] != -1) return dp[n][amount];

        if(coins[n-1] <= amount) {
            return dp[n][amount] = Math.min(1 + F(coins, n, amount - coins[n-1], dp), F(coins, n-1, amount, dp));
        }
        return dp[n][amount] = F(coins, n-1, amount, dp);
    }
    public int coinChange(int[] coins, int amount) 
    {
        Arrays.sort(coins);
        int n = coins.length;

        long[][] dp = new long[n+1][amount+1];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= amount; j++)
                dp[i][j] = -1;

        long ans = F(coins, n, amount, dp);

        return (ans >= Integer.MAX_VALUE) ? -1: (int)ans;
    }
}

/*

sort(coins)

coins = [1,2,5], amount = 11
n = 3
F(coins, n, amount) {
    if(amount == 0) return 1;
    if(amount < 0) return INT_MAX;

    if(amount <= coins[n-1]) {
        return min(F(coins, n, amount - coins[n-1]), F(coins, n-1, amount));
    }
    return F(coins, n-1, amount)
}

*/