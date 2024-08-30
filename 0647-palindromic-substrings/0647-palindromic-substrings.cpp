class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length(), ans = 0;
        bool dp[1005][1005] = {false};
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            ans++;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++;
            }
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

/*

abbajkjiuurruui



*/