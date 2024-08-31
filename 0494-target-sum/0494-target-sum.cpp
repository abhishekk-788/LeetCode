class Solution {
public:
    int dp[3005][25];
    int F(vector<int>& nums, int s, int n)
    {
        if(n == 0 && s == 0) return 1;
        if(n == 0 && s != 0) return 0;
        
        if(dp[1001 + s][n] != -1) return dp[1001 + s][n];
        
        return dp[1001 + s][n] = F(nums, s+nums[n-1], n-1) + F(nums, s-nums[n-1], n-1);
    }
    int findTargetSumWays(vector<int>& nums, int s) 
    {
        memset(dp, -1, sizeof(dp));
        return F(nums, s, nums.size());
    }
};