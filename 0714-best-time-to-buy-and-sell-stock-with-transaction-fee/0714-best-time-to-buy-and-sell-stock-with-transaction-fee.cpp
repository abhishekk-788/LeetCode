class Solution {
public:
    int dp[50005][2];
    int solve(vector<int>& prices, int i, int n, int buy, int fee) 
    {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        
        if(buy) {
            int buyKaro = -prices[i] - fee + solve(prices, i+1, n, 0, fee);
            int skipKaro = solve(prices, i+1, n, 1, fee);
            
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = +prices[i] + solve(prices, i+1, n, 1, fee);
            int skipKaro = solve(prices, i+1, n, buy, fee);
            
            profit = max(sellKaro, skipKaro);
        }
        
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(prices, 0, n, 1, fee);
    }
};