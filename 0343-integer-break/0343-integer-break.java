class Solution { 
    int F(int n, int cnt, int[] dp)
    {
        if( n == 1) return 1;
        if( n == 0) return (cnt <= 1) ? 0: 1;
        
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = Math.max(ans, i * F(n - i, cnt+1, dp));
        }
        
        return dp[n] = ans;
    }
    public int integerBreak(int n) 
    {
        int[] dp = new int[n+1];
        Arrays.fill(dp, -1);

        return F(n, 0, dp);
    }
}