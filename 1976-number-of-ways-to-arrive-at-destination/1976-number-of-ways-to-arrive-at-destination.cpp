class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        const long MOD = 1e9 + 7;
        unordered_map<int, vector<pair<int, int>>> G;

        for(int i = 0; i < roads.size(); i++)
        {
            G[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            G[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;

        vector<pair<long, long>> dp(n, {1e18, 0});   // {shortest_time, number_of_ways}

        pq.push({0, 0});
        dp[0] = {0, 1};

        while (!pq.empty()) 
        {
            auto [currentTime, node] = pq.top();
            pq.pop();

            if (currentTime > dp[node].first) continue;

            for (auto& [neighbor, travelTime] : G[node]) 
            {
                long newTime = currentTime + travelTime;
                
                if (newTime < dp[neighbor].first) {
                    dp[neighbor] = {newTime, dp[node].second};
                    pq.push({newTime, neighbor});
                } 
                else if (newTime == dp[neighbor].first) {
                    dp[neighbor].second = (dp[neighbor].second + dp[node].second) % MOD;
                }
            }
        }

        return dp[n-1].second;
    }
};
