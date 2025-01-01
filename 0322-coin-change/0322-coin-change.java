class Solution {
    long F(int[] coins, int amount, long[] dp) {
        if (amount == 0) return 0;
        if (amount < 0) return Integer.MAX_VALUE;

        if (dp[amount] != -1) return dp[amount];

        long minCoins = Integer.MAX_VALUE;
        for (int coin : coins) 
        {
            long res = F(coins, amount - coin, dp);
            if (res != Integer.MAX_VALUE - 1) {
                minCoins = Math.min(minCoins, res + 1);
            }
        }

        dp[amount] = minCoins;
        return dp[amount];
    }

    public int coinChange(int[] coins, int amount) {
        long[] dp = new long[amount + 1];
        Arrays.fill(dp, -1);

        long ans = F(coins, amount, dp);

        return (ans >= Integer.MAX_VALUE) ? -1 : (int)ans;
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