class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int, vector<pair<int, int>>> G;
        for(auto &flight : flights) 
        {
            int src = flight[0], dest = flight[1], wei = flight[2];
            G[src].push_back({dest, wei});
        }

        vector<int> dist(n, INT_MAX);
        queue<vector<int>> q;
        
        q.push({0, 0, src}); // stops, dist, node

        while(!q.empty()) 
        {
            auto front = q.front();
            int stops = front[0];
            int cost = front[1];
            int node = front[2];
            
            q.pop();

            if(stops > k) continue;

            for(auto &nei : G[node]) 
            {
                int nei_node = nei.first;
                int nei_wei = nei.second;

                if(dist[nei_node] > cost + nei_wei && stops <= k) 
                {
                    dist[nei_node] = cost + nei_wei;
                    q.push({stops+1, dist[nei_node], nei_node});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1: dist[dst];
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