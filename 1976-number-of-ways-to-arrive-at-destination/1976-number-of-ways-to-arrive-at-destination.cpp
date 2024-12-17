class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const long MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> graph;

        for (int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;

        vector<vector<long>> dp(n, vector<long>(2, 1e18));
        dp[0][0] = 0;
        dp[0][1] = 1;

        pq.push({0, 0});

        while (!pq.empty()) 
        {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dp[node][0]) continue;

            for (auto& [neighbor, weight] : graph[node]) 
            {
                long newTime = time + weight;

                if (newTime < dp[neighbor][0]) {
                    dp[neighbor][0] = newTime;
                    dp[neighbor][1] = dp[node][1];
                    pq.push({newTime, neighbor});
                } 
                else if (newTime == dp[neighbor][0]) {
                    dp[neighbor][1] = (dp[neighbor][1] + dp[node][1]) % MOD;
                }
            }
        }

        return dp[n-1][1];
    }
};
