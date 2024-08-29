class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0, maxProfit = 0, buy = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < buy) buy = min(buy, prices[i]);
            else
            {
                profit = prices[i] - buy;
                maxProfit = max(profit, maxProfit);
            }
        }
        
        return maxProfit;
    }
};