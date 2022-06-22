class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for(auto &ele: nums) 
        {
            mp[ele]++;
        }
        
        int cnt = 0;
        for(auto &ele: mp) 
        {
            if(k != 0 && mp.count(ele.first+k) == 1) cnt++;
            if(k == 0) cnt += mp[ele.first] > 1 ? 1: 0;
        }
        
        return cnt;
    }
};