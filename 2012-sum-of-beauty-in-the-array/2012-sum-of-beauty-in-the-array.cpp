class Solution {
public:
    int sumOfBeauties(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> isGreaterElementOnLeft(n, false), isSmallerElementOnRight(n, false);
        
        int ele = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(ele >= nums[i]) {
                isGreaterElementOnLeft[i] = true;
            }
            ele = max(ele, nums[i]);
        }
        ele = nums[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            if(ele <= nums[i]) {
                isSmallerElementOnRight[i] = true;
            }
            ele = min(ele, nums[i]);
        }
        
        int totalSum = 0;
        for(int i = 1; i < n-1; i++)
        {
            // cout << "isGreaterElementOnLeft: " << isGreaterElementOnLeft[i];
            // cout << " isSmallerElementOnRight: " << isSmallerElementOnRight[i] << "\n";
            if(isGreaterElementOnLeft[i] == false && isSmallerElementOnRight[i] == false) {
                totalSum += 2;
            }
            else if(nums[i] > nums[i-1] && nums[i] < nums[i+1]) {
                totalSum += 1;
            }
        }
        
        return totalSum;
    }
};


/*

7 3 4 5 9 1 6


7


*/