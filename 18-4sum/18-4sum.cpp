class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < n-3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i+1; j < n-2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                long long s1 = nums[i] + nums[j];
                int x = j+1, y = n-1;
                
                while(x < y)
                {
                    long long s2 = nums[x] + nums[y];
                    if(s1 + s2 == target)
                    {
                        vector<int> v = {nums[i], nums[j], nums[x], nums[y]};
                        res.push_back(v);
                        
                        x++; y--;
                        
                        while (x < n - 1 && nums[x] == nums[x - 1]) x++;
                        while (y > 0 && nums[y] == nums[y + 1]) y--;
                    
                    }
                    else if (s1 + s2 < target) x++;
                    else y--;
                }
            }
        }
        
        return res;
    }
};

/*

-2 -1 0 0 1 2

*/