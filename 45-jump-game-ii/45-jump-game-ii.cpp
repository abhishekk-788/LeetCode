class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size(), idx = 0, jumps = 1, rnge = nums[0], mx_rnge = rnge;
        
        if(n <= 1) return 0;
        if(rnge >= n-1) return jumps;
        
        while(1)
        {
            if(idx <= rnge)
            {
                mx_rnge = max(mx_rnge, idx + nums[idx]);
                idx++;
            }
            else 
            {
                jumps++;
                
                rnge = mx_rnge;
                mx_rnge = rnge;
                
                // cout << rnge << " " << mx_rnge << "\n";
                
                if(rnge >= n-1) break;
            }
        }
        
        return jumps;
    }
};