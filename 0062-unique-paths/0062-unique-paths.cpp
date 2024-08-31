class Solution {
public:
    int dp[101][101];
    int solve(int i, int j, int m, int n)
    {
        if(i < 0 || i > m || j < 0 || j > n) return 0;
        if(i == m && j == n) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = solve(i+1, j, m, n);
        int y = solve(i, j+1, m, n);
        
        return dp[i][j] = x+y;
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m-1, n-1);
    }
};