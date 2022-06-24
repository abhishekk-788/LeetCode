class Solution {
public:
    unordered_map<int, int> mp;
    int longestConsecutive(vector<int>& nums) 
    {
        mp.clear();
        if(nums.size() == 0) return 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        int res = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.count(nums[i]-1) == 1) continue;
            else
            {
                int x = nums[i]+1;
                while(mp.count(x))
                {
                    x++;
                }
                res = max(res, x-nums[i]);
            }
        }
        return res;
    }
};

/*

0,3,7,2,5,8,4,6,0,1
0 1
3 4
7 1
2 2
5 2
8 1
4 4
6 


*/