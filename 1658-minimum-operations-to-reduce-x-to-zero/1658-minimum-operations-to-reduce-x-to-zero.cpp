class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int s = 0, n = nums.size();
        for(auto &ele: nums) {
            s += ele;
        }
        
        if(s == x) return n;
        
        int y = s - x, sm = 0, ans = -1;
        unordered_map<int, int> mp;
        
        mp[0] = -1;
        for(int i = 0; i < n; i++) 
        {
            sm += nums[i];
            if(mp.count(sm - y) == 1) {
                ans = max(ans, i - mp[sm-y]);
            }
            
            mp[sm] = i;
        }
        
        
        return ans == -1 ? -1: n - ans;
    }
};

/*

1 1 4 2 3
1 2 6 8 11

30 - 20
3,2,20,1,1,3

3 + 3 + 2 + 1 + 1

1 1 4 2 3
1


*/