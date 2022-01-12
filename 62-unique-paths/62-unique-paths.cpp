class Solution {
public:
    int dp[105][105];
    int F(int m, int n)
    {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        return dp[m][n] = F(m-1, n) + F(m, n-1);
    }
    int uniquePaths(int m, int n) 
    {
        memset(dp, -1, sizeof(dp));
        return F(m-1, n-1);
    }
};