class Solution {
public:
    int dp[505][505];
    int solve(vector<int>& nums, int l, int r)
    {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int ans = INT_MIN;
        for(int i = l; i <= r; i++)
        {
            int x = nums[l-1] * nums[i] * nums[r+1];
            
            int lv = solve(nums, l, i-1);
            int rv = solve(nums, i+1, r);
            
            ans = max(ans, x + lv + rv);
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, 1, nums.size()-2);
    }
};

/*

[3,1,5,8]



*/