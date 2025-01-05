class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int numi = nums[0], numj = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            numi = min(numi, nums[i]);
            if(nums[i] > numi) 
            {
                if(numj == -1) numj = nums[i];
                else 
                {
                    if(nums[i] < numj) numj = nums[i];
                    if(nums[i] > numj) return true;
                }
            }
        }    
        return false;
    }
};