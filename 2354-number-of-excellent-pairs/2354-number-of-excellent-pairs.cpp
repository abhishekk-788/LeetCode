class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp; 
        vector<int> dp;
        
        for(int i = 0; i < nums.size(); i++) 
        {
            int cnt = 0;
            for(int k = 0; k < 31; k++) 
            {
                if(nums[i] & (1 << (k))) {
                    cnt++;
                }
            }
            
            mp[nums[i]] = cnt;
        }
        
        for(auto &x: mp) {
            dp.push_back(x.second);
        }
        
        sort(dp.begin(), dp.end());
        
        long long ans = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), k - dp[i]);
            ans += (dp.end() - it);
        }
        return ans;
    }
};

/*

1, 2, 3

0 0 1  -- 1
0 1 0  -- 1
0 1 1  -- 2

1 0 0  -- 1
0 1 1  -- 2 

1 1 1 = 3

0 1 0
0 1 0

1 -> 3, 2 -> 1
1 -> 3, 2 -> 1

o = n, a = 3



1, 1, 2, 3



*/