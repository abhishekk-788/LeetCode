class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int n = nums.size(), mx = 1;
        vector<vector<int>> dp(n + 1, vector<int>(2, 1));

        for(int i = 1; i <= n; i++) 
        {
            for(int j = i + 1; j <= n; j++) 
            {
                if(nums[j-1] > nums[i-1]) 
                {
                    int val = dp[i][0] + 1;
                    int cnt = dp[i][1];

                    if(dp[j][0] < val) 
                    {
                        dp[j][0] = val;
                        dp[j][1] = cnt;
                        mx = max(mx, dp[j][0]);
                    }
                    else if(dp[j][0] == val) 
                    {
                        dp[j][1] += cnt;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dp[i][0] == mx) {
                ans += dp[i][1];
            }
        }

        return ans;
    }
};

// 1 3 5 4 7

// 1 1 1 1 1 1
// 1 1 1 1 1 1
// 1 1 1 1 1 1 
// 1 1 1 1 1 1
// 1 1 1 1 1 1 
// 1 1 1 1 1 1