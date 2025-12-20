class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), mx = 1;
        vector<int> dp(n, 1);

        sort(pairs.begin(), pairs.end());

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(pairs[j][0] > pairs[i][1]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    mx = max(mx, dp[j]);
                }
            }
        }

        return mx;
    }
};