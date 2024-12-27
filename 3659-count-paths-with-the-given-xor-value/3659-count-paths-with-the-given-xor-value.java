class Solution {
    public int countPathsWithXorValue(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][16];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < 16; l++) {
                    dp[i][j][l] = -1;
                }
            }
        }

        return fun(n, m, grid, 0, 0, k, 0, dp);
    }

    static int fun(int n, int m, int[][] grid, int i, int j, int k, int ans,int[][][] dp) {

        if(i == n - 1 && j == m - 1 && (ans ^ grid[n-1][m-1]) == k) return 1;
        if(i >= n || j >= m) return 0;

        if(dp[i][j][ans] != -1) return dp[i][j][ans];

        int temp = ans ^ grid[i][j];

        int right = fun(n, m, grid, i, j + 1, k, temp, dp);
        int down = fun(n, m, grid, i + 1, j, k, temp, dp);

        return dp[i][j][ans] = (right + down) % (int)(1e9 + 7);
    }
}
