class Solution {
public:
    int dp[105][105];
    int ex, ey, m, n, ans = 0;
    void F(vector<vector<int>> &grid, int i, int j, int cnt)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || dp[i][j]) return;
        if(i == ex && j == ey) 
        {
            if(cnt == 0) ans++;
            // cout << cnt << "\n";
            return;
        }
        
        dp[i][j] = 1;
        
        F(grid, i-1, j, cnt-1);
        F(grid, i, j-1, cnt-1);
        F(grid, i+1, j, cnt-1);
        F(grid, i, j+1, cnt-1);
        
        dp[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& obstacleGrid) 
    {
        memset(dp, 0, sizeof(dp));
        
        m = obstacleGrid.size(); n = obstacleGrid[0].size();
        int sx, sy, cnt = m * n;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1) {
                    sx = i; sy = j;
                }
                if(obstacleGrid[i][j] == 2) {
                    ex = i; ey = j;
                }
                if(obstacleGrid[i][j] == -1) {
                    cnt--;
                }
            }
        }
    
        cnt = cnt-1;
        
        F(obstacleGrid, sx, sy, cnt);
        return ans;
    }
};