class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), s = nums[0], ans = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i-1]) {
                s += nums[i];
            }
            else s = nums[i];

            ans = max(ans, s);
        }

        return ans;
    }
};