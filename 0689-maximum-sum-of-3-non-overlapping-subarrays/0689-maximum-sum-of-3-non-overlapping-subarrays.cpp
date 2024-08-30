class Solution {
public:
    int dp[20005][4];
    vector<int> indexDp[20005][4];
    
    pair<int, vector<int>> solve(vector<int>& nums, int i, int n, int k, int limit) 
    {
        if (i >= n || limit == 0) return {0, {}};
        if (dp[i][limit] != -1) return {dp[i][limit], indexDp[i][limit]};
    
        int value = nums[i + k - 1] - (i == 0 ? 0 : nums[i - 1]);
        
        auto take = solve(nums, i + k, n, k, limit - 1);
        take.first += value;
        
        take.second.insert(take.second.begin(), i);
        
        auto doNotTake = solve(nums, i + 1, n, k, limit);
        
        if (take.first > doNotTake.first) 
            dp[i][limit] = take.first, indexDp[i][limit] = take.second;
        else if (take.first < doNotTake.first) 
            dp[i][limit] = doNotTake.first, indexDp[i][limit] = doNotTake.second;
        else
            if (take.second < doNotTake.second) 
                dp[i][limit] = take.first, indexDp[i][limit] = take.second;
            else
                dp[i][limit] = doNotTake.first, indexDp[i][limit] = doNotTake.second;
        
        return {dp[i][limit], indexDp[i][limit]};
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        auto result = solve(nums, 0, n - k + 1, k, 3);
        return result.second;
    }
};