class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> G;
public:
    int dijsktra(int src, int n, int distanceThreshold) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) 
        {
            auto itr = pq.top();
            pq.pop();
            
            int wt = itr.first, node = itr.second;
            
            for(auto neighbor: G[node]) 
            {
                if(wt + neighbor.second < dist[neighbor.first]) 
                {
                    dist[neighbor.first] = wt + neighbor.second;
                    pq.push({dist[neighbor.first], neighbor.first});
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] > distanceThreshold) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        for(int i = 0; i < edges.size(); i++) {
            G[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            G[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        int mnCitiesReachable = 0, ans = -1;
        for(int i = 0; i < n; i++) 
        {
            int notReachable = dijsktra(i, n, distanceThreshold);
            if(notReachable == mnCitiesReachable) {
                ans = max(ans, i);
            }
            if(notReachable > mnCitiesReachable) {
                ans = i;
                mnCitiesReachable = notReachable;
            }
        }    
        
        return ans;
    }
};


/*

Return the city with the smallest number of cities that are reachable and distance is at most distanceThreshold

0 -> 1
0 -> 1 -> 3

Dijkstra for all vertices


*/