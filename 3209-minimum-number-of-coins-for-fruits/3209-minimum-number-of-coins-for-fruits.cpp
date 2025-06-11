class Solution {
public:
    int helper(int ind,int n, vector<int>& prices,int offer, vector<vector<int>> &dp)
    {
        if(ind == n) return 0;
        if(ind > n) return 1e8;
        if(dp[ind][offer] != -1) return dp[ind][offer];

        int take = prices[ind] + helper(ind + 1, n, prices, ind + 1, dp);  
        int nottake = 1e8;

        if(offer){
            nottake = helper(ind+1, n, prices, offer-1, dp);
        }
        return dp[ind][offer] = min(take, nottake);
    }
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(0, n, prices, 0, dp);
    }
};