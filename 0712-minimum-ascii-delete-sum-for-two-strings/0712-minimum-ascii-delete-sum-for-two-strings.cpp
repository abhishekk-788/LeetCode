class Solution {
public:
    int solve(string s1, string s2, int x, int y)
    {
        if(x == 0 && y == 0) return 0;
        
        if(x == 0) return (int)s2[y-1] + solve(s1, s2, x, y-1);
        if(y == 0) return (int)s1[x-1] + solve(s1, s2, x-1, y);
        
        if(s1[x-1] == s2[y-1]) return solve(s1, s2, x-1, y-1);
        return min((int)s1[x-1] + solve(s1, s2, x-1, y), (int)s2[y-1] + solve(s1, s2, x, y-1));
    }
    int minimumDeleteSum(string s1, string s2) {
        
        int x = s1.length(), y = s2.length();
        vector<vector<int>> dp(x+1, vector<int> (y+1, 0));
        
        for(int i = 1; i <= x; i++) {
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
        }
        for(int j = 1; j <= y; j++) {
            dp[0][j] = dp[0][j-1] + (int)s2[j-1];
        }
        
        dp[0][0] = 0;
        
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min((int)s1[i-1] + dp[i-1][j], (int)s2[j-1] + dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};