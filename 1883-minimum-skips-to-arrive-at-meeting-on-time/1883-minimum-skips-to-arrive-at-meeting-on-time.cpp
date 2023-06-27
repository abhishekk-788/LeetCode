class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 1e18));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i - 1][0] + dist[i - 1] + speed - 1) / speed * speed;
            for (int j = 1; j <= i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + dist[i - 1], (dp[i - 1][j] + dist[i - 1] + speed - 1) / speed * speed);
            }
        }

        for (int i = 0; i <= n; i++) {
            if (dp[n][i] <= 1LL * speed * hoursBefore)
                return i;
        }

        return -1;
    }
};
