class Solution {
public:
    int solve(string s, string t, int x, int y)
    {
        if(x == 0 && y == 0) return 1;
        if(x == 0 || y == 0) return 0;
        
        int ans = 0;
        if(s[x-1] == t[y-1])
            ans += solve(s, t, x-1, y-1);
            
        ans += solve(s, t, x-1, y);
        return ans;
    }
    
    int numDistinct(string s, string t) {
        int x = s.length(), y = t.length();
        
        vector<vector<int>> dp(x+1, vector<int> (y+1, 0));
        for(int i = 0; i <= x; i++)
        {
            for(int j = 0; j <= y; j++)
            {
                long long ans = 0;
                if(j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s[i-1] == t[j-1])
                    ans += (long long) dp[i-1][j-1];
                
                ans += (long long) dp[i-1][j];
                
                dp[i][j] = ans;
            }
        }
        
        return (int) dp[x][y];
    }
};

/*

babgbag
bag





*/