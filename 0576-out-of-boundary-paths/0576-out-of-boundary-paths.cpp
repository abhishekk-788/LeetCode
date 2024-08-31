class Solution {
public:
    long long dp[51][51][51];
    long long solve(int i, int j, int m, int n, int maxMove)
    {
        if(maxMove < 0) return 0;
        if(i == m || j == n || i < 0 || j < 0) return 1;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        long long a = solve(i+1, j, m, n, maxMove-1);
        long long b = solve(i-1, j, m, n, maxMove-1);
        long long c = solve(i, j+1, m, n, maxMove-1);
        long long d = solve(i, j-1, m, n, maxMove-1);
        
        return dp[i][j][maxMove] =  (a + b + c + d) % 1000000007; 
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove);    
    }
};