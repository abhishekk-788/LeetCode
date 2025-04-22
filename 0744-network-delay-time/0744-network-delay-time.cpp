class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> G;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        for(int i = 0; i < times.size(); i++) {
            G[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while(!pq.empty()) 
        {
            auto itr = pq.top();
            pq.pop();
            
            int wt = itr.first;
            int node = itr.second;
            
            for(auto neighbor: G[node]) 
            {
                if(wt + neighbor.second < dist[neighbor.first]) 
                {
                    dist[neighbor.first] = wt + neighbor.second;
                    pq.push({dist[neighbor.first], neighbor.first});
                }
            }
        }
        
        int mxTime = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == 1e9) return -1;
            mxTime = max(mxTime, dist[i]);
        }
        
        return mxTime;
    }
};