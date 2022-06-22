class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX, res = -1;
        
        for(int i = 0; i < n-2; i++)
        {
            int l = i+1, r = n-1;
            while(l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if(s == target) return s;
                
                if(s < target) l++;
                else r--;
                
                if(abs(s-target) < diff)
                {
                    diff = abs(s-target);
                    res = s;
                }
            }
        }
        
        return res;
    }
};