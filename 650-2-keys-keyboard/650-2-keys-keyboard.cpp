class Solution {
public:
    int dp[1005][1005];
    int F(int i, int k, int n)
    {
        if(i == n) return 0;
        if(i > n) return 100000;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        return dp[i][k] = min(1 + F(i+k, k, n), 2 + F(2*i, i, n));
    }
    int minSteps(int n) 
    {
        int i = 2, k = 1;
        if(n == 1) return 0;
        
        memset(dp, -1, sizeof(dp));
        
        return 2 + F(i, 1, n);
    }
};

/*

AAAAAAAA

*/