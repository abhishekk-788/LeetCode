class Solution {
public:
    int dp[10005][205];
    bool solve(vector<int> &nums, int n, int target)
    {
        if(target < 0) return false;
        if(target == 0) return true;
        
        if(dp[target][n] != -1) return dp[target][n];
        
        if(n == 0) return false;
        return dp[target][n] = solve(nums, n-1, target-nums[n-1]) || solve(nums, n-1, target);
    }
    bool canPartition(vector<int>& nums) 
    {
        int s = 0, n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            s += nums[i];
        }
        
        if(s % 2 == 1) return 0;
        return solve(nums, n, s/2);
    }
};

/*

22
11

*/