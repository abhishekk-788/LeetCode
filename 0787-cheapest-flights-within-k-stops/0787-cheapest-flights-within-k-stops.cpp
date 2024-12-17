class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int, vector<pair<int, int>>> G;
        vector<vector<int>> dp(n, vector<int>(k + 2, 1e9));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (auto& flight : flights) {
            G[flight[0]].push_back({flight[1], flight[2]});
        }

        dp[src][0] = 0;
        pq.push({0, src, 0}); // {cost, node, stops}

        while (!pq.empty()) 
        {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], node = curr[1], stops = curr[2];

            for (auto& neighbor : G[node]) 
            {
                int nextNode = neighbor.first, price = neighbor.second;
                if (stops < k + 1 && cost + price < dp[nextNode][stops + 1]) {
                    dp[nextNode][stops + 1] = cost + price;
                    pq.push({dp[nextNode][stops + 1], nextNode, stops + 1});
                }
            }
        }

        int minCost = 1e9;
        for (int i = 0; i <= k + 1; i++) 
        {
            minCost = min(minCost, dp[dst][i]);
        }

        return (minCost == 1e9) ? -1 : minCost;
    }

};

/*

5
[[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
0
2
2

*/

/*

0 -> 1

*/