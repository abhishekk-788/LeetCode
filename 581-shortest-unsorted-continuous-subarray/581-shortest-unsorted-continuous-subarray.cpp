class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> arr = nums;
        sort(nums.begin(), nums.end());
        
        int x = -1, y = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != arr[i])
            {
                if(x == -1) x = i;
                y = i;
            }
        }
        
        return (x == -1) ? 0: y-x+1;
    }
};