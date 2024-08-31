class Solution {
public:
    int dp[5005][2][2];
    int solve(vector<int>& prices, int i, int n, int buy, int cool) 
    {
        if(i == n) return 0;
        if(dp[i][buy][cool] != -1) return dp[i][buy][cool];
        
        if(cool) return solve(prices, i+1, n, 1, 0);
        
        int profit = 0;
        
        if(buy) {
            int buyKaro = -prices[i] + solve(prices, i+1, n, 0, 0);
            int skipKaro = solve(prices, i+1, n, 1, 0);
            
            profit = max(buyKaro, skipKaro);
        }
        else {
            int sellKaro = +prices[i] + solve(prices, i+1, n, 1, 1);
            int skipKaro = solve(prices, i+1, n, buy, 0);
            
            profit = max(sellKaro, skipKaro);
        }
        
        return dp[i][buy][cool] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, n, 1, 0);
    }
};

/*

1 2 3 5 3 6 7 3
  1 

*/