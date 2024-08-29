class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long max_diff = nums[0] - nums[1];
        
        int mx = max(nums[0], nums[1]);
        long long result = 0LL;
        
        for (int k = 2; k < n; k++) 
        {
            max_diff = max(max_diff, (long long)mx - nums[k - 1]);
            mx = max(mx, nums[k]);
            
            result = max(result, max_diff * nums[k]);
        }
        return result;
    }
};

/*

max((nums[i] - nums[j]) * nums[k]) 

max((x - y) * z) 

[10,13,6,2]

*/