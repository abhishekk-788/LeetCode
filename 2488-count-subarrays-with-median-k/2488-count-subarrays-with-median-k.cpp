class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size(), idx = -1;
        for(int i = 0; i < n; i++) 
        {
            if(nums[i] == k) {
                nums[i] = 0; idx = i;
            }
            else if(nums[i] < k) nums[i] = -1;
            else nums[i] = 1;
        }
        
        if(idx == -1) return 0;
        
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        
        for(int i = idx; i >= 0; i--)
        {
            sum += nums[i];
            mp[sum]++;
        }
        
        sum = 0;
        for(int i = idx; i < n; i++) 
        {
            sum += nums[i];
            if(mp.count(-sum) == 1) ans += mp[-sum];
            if(mp.count(-sum + 1) == 1) ans += mp[-sum+1];
        }
        
        return ans;
    }
};

/*

4

1 4 5



*/