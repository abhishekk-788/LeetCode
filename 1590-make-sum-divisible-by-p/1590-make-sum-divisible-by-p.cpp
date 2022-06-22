#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        unordered_map<int, int> mp;
        
        ll n = nums.size(), ts = 0;
        for(int i = 0; i < n; i++) {
            ts += (nums[i] % p) * 1LL;
        }
        
        
        if(ts % p == 0) return 0;
        int r = ts % p;
        
        ll s = 0;
        int ans = n;
        
        mp[0] = -1;
        
        for(int i = 0; i < n; i++) 
        {
            s += nums[i];
            s = s % p;

            int x = (s - r) % p;
            x = x < 0 ? x+p: x;
            
            if(mp.count(x) == 1) {
                ans = min(ans, i - mp[x]);
            }
            
            mp[s] = i;
        }
        
        return ans == n ? -1: ans;
    }
};

/*

6 0 5 7

*/