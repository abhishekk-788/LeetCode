class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0, j = 0, s = 0, ans = n+1;
        while(j < n) 
        {
            if(s >= target) 
            {
                ans = min(ans, j - i);
                s -= nums[i];
                
                i++;
            }
            else 
            {
                s += nums[j];
                j++;
            }

            cout << i << " " << j << " " << s << " " << ans << "\n";
        }


        while(s >= target) {
            s -= nums[i];

            ans = min(ans, j - i);
            i++;
        }

        return ans == n+1 ? 0: ans;
    }
};

/*

[2, 3, 1, 2, 4, 3]
[2, 5, 6, 8, 12, 15]


*/