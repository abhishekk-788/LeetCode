class Solution {
    public long MOD = 1000000007;
    public long F(int n, int k, int target, long dp[][][])
    {
        if(n == 0 && target == 0) return 1;
        if(n == 0 || target < 0) return 0;

        if(dp[n][k][target] != -1) return dp[n][k][target];

        long total = 0;
        for(int i = 1; i <= k; i++)
        {
            total = (total + F(n-1, k, target-i, dp)) % MOD;
        } 
        return dp[n][k][target] = total;
    }
    public int numRollsToTarget(int n, int k, int target) {
        long dp[][][] = new long[n+1][k+1][target+1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                for(int l = 0; l <= target; l++) {
                    dp[i][j][l] = -1;
                }
            }
        }

        return (int)F(n, k, target, dp);
    }
}