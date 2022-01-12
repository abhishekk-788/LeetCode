class Solution {
public:
    int dp[105][105];
    int F(vector<vector<int>> &grid, int m, int n)
    {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0 || grid[m][n]) return 0;
        
        if(dp[m][n] != -1) return dp[m][n];
    
        return dp[m][n] = F(grid, m-1, n) + F(grid, m, n-1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        memset(dp, -1, sizeof(dp));
        
        if(obstacleGrid[0][0]) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return F(obstacleGrid, m-1, n-1);
    }
};