class Solution {
public:
    int dp[1005][5][105];
    int solve(int i, int n, int buy, vector<int> &prices, int limit)
    {
        if(i == n || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy) 
        {
            int buyKaro = -prices[i] + solve(i + 1, n, 0, prices, limit);
            int skipKaro = 0 + solve(i + 1, n, 1, prices, limit);
            
            profit = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = +prices[i] + solve(i + 1, n, 1, prices, limit - 1);
            int skipKaro = 0 + solve(i + 1, n, 0, prices, limit);
            
            profit = max(sellKaro, skipKaro);
        }
        return dp[i][buy][limit] = profit;
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(0, n, 1, prices, k);
    }
};