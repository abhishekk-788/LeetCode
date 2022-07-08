class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        vector<long> dp(n+1);
        long mod = 1000000007, s = 0, ans = 0;
        
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            long j = dp[max(i-delay, 0)];
            long k = dp[max(i-forget, 0)];
            s += (j - k + mod) % mod;
            
            dp[i] = s;
        }
        
        for(int i = n-forget+1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
};

/*

10 4 7
0 1 2 3 4 5 6 7 8 9 10
1 0 0 0 1 1 1 0 1 2 3

6 2 4
1 1 2 3 

0 1 2 3 4 5 6 7 8 9 0
0 1 0 1 1 1 2 2 3 4 5

0 + 1 = 3  (1)
0 + 1 + 2 = 4  (1)  
1 + 2 + 3 = 5  (2 - 1)
2 + 3 + 4 = 6  (2 - 0)
3 + 4 + 5 = 7  (3 - 1)


10 1 7

1 1 2 4 8 16 32 63 126 249 494


s += dp[i-delay];
s -= dp[i-forget];

i = 0, j = 4
i = 0, j = 5
        

1 2 4 6

*/