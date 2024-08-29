class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> greatestElementOnRight(n, -1);
        
        int ele = nums[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            greatestElementOnRight[i] = ele;
            ele = max(ele, nums[i]);
        }  
        
        long long maxRes = -1, x = nums[0];
        for(int i = 1; i < n; i++)
        {
            long long y = nums[i];
            if((x - y) > 0) {
                long long res = (x - y) * greatestElementOnRight[i];
                maxRes = max(res, maxRes);
            }
            
            x = max(x, nums[i] * 1LL);
            y = min(y, nums[i] * 1LL);
        }
        
        return maxRes == -1 ? 0: maxRes;
    }
};

/*

max((nums[i] - nums[j]) * nums[k]) 

max((x - y) * z) 

[10,13,6,2]

*/