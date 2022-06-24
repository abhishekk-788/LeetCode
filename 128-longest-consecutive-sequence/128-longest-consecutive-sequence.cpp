class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> S;
        for(int i = 0; i < nums.size(); i++)
        {
            S.insert(nums[i]);
        }
        
        int mx = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int curr_mx = 1;
            if(S.find(nums[i] - 1) == S.end())
            {
                int x = nums[i];
                while(S.find(x+1) != S.end())
                {
                    x = x+1;
                    curr_mx++;
                }
            }
            mx = max(mx, curr_mx);
        }
        return mx;
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