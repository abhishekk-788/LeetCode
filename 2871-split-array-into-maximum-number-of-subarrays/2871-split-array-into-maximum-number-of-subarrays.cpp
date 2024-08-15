class Solution {
public:
    int maxSubarrays(vector<int>& nums) 
    {
        int ans = nums[0], n = nums.size();
        for(int i = 1; i < n; i++)
            ans = ans & nums[i];
        
        if(ans != 0) return 1;
        
        int s = -1, cnt = 0;
        for(int i = 0; i < n; i++) 
        {
            if(s == -1) s = nums[i];
            else s = s & nums[i];
            
            
            if(s == ans) 
            {
                s = -1;
                cnt++;
            }
        }
        
        return cnt;
    }
};

/*


[22,21,29,22]

10110
10101

11101
10110

10100


101
111
001
011


*/