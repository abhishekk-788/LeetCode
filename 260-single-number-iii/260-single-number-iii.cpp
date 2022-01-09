class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            res ^= nums[i];
        }
        
        int pos;
        for(int i = 0; i < 32; i++)
        {
            if((1 << i) & res) {
                pos = i;
                break;
            }
        }
        
        // cout << res << " " << pos << "\n";
        
        int a = 0, b = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] & (1 << pos))
            {
                a ^= nums[i];
            }
        }
        
        b = res ^ a;
        return {a, b};
    }
};

/*

011
101
---
110

010

001
001
010
010
011
101


010

*/