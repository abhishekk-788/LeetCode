class Solution {
    int[][] dp;
    public int lcs(String s, String t, int n, int m)
    {
        if(m == 0) return 1;
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        int x = 0;
        if(s.charAt(n-1) == t.charAt(m-1)) {
            x = lcs(s, t, n-1, m-1);
        }

        return dp[n][m] = x + lcs(s, t, n-1, m);
        
    }
    public int numDistinct(String s, String t) 
    {
        int n = s.length(), m = t.length();
        dp = new int[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        return lcs(s, t, n, m);    
    }
}