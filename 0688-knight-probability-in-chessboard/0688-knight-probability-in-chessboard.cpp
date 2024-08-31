class Solution {
public:
    double dp[26][26][105];
    double solve(int n, int r, int c, int k)
    {
        if(r < 0 || c < 0 || r >= n || c >= n) return 0;
        if(k == 0) return 1;
        
        if(dp[r][c][k] != -1.0) return dp[r][c][k];
        
        double temp = 0.0;
        temp = solve(n,r+2,c+1,k-1) +
            solve(n,r+2,c-1,k-1) +
            solve(n,r-2,c-1,k-1) +
            solve(n,r-2,c+1,k-1) +
            solve(n,r+1,c+2,k-1) +
            solve(n,r+1,c-2,k-1) +
            solve(n,r-1,c+2,k-1) +
            solve(n,r-1,c-2,k-1);
        
        temp = temp/8;
        return dp[r][c][k] = temp;
    }
    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int m = 0; m <= k; ++m) {
                    dp[i][j][m] = -1.0;
                }
            }
        }
        return solve(n, row, column, k);
    }
};