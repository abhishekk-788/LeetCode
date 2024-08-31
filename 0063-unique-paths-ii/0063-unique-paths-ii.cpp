class Solution {
public:
    int dp[101][101];
    int obj[101][101];
    int solve(int i, int j, int m, int n)
    {
        if(i < 0 || i > m || j < 0 || j > n || obj[i][j] == 1) return 0;
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j]) {
                    obj[i][j] = 1;
                }
            }
        }
        
        return solve(0, 0, m-1, n-1);
    }
};