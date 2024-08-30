class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) 
        {
            if (s[i] != s[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) 
    {
        int n = s.length(), ans = 0;
        int dp[1005][1005];
        
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            ans += 1;
            for(int j = i+1; j < n; j++)
            {
                if(dp[i][j] == -1 && isPalindrome(s, i, j)) {
                    ans++;
                }
                dp[i][j] = 1;
            }
        }
        
        return ans;
    }
};

/*

abbajkjiuurruui



*/