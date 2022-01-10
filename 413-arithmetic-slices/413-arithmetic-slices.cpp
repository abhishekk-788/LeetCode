class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n = nums.size(), cnt = 0, ans = 0;
        
        for(int i = 2; i < n; i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                cnt++;
            }
            else
            {
                ans += cnt * (cnt+1) / 2;
                cnt = 0;
            }
        }
        
        ans += cnt * (cnt+1) / 2;
        return ans;
    }
};

/*

1 2 3 4 5


*/