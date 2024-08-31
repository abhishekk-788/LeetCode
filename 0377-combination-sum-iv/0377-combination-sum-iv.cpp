class Solution {
public:
    int dp[1005];
    int solve(vector<int>& nums, int target)
    {
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];
        
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt += solve(nums, target - nums[i]);
        }
        return dp[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target);
    }
};