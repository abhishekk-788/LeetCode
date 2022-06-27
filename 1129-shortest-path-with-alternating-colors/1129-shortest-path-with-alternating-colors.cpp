class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int,vector<int>> red;
        unordered_map<int,vector<int>> blue;
        
        vector<int> path(n,INT_MAX);
        
        for(int i = 0;i <redEdges.size();i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        for(int i = 0;i <blueEdges.size();i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        queue<pair<int,int>> q;
        set<pair<int,int>> seen;
        
        q.push({0, 0});
        q.push({0, 1});
        
        int steps = 0 ;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                int node = q.front().first;
                int color = q.front().second;
                
                seen.insert(q.front());
                q.pop();
                
                path[node] = min(path[node],steps);
                
                if (color == 0) 
                {
                    for(int v : blue[node]) 
                    {
                        if (seen.find({v,1})==seen.end()) {
                            q.push({v,1});
                        }
                    }
                }
                else 
                {
                    for(int v : red[node]) 
                    {
                        if (seen.find({v,0})==seen.end()) {
                            q.push({v,0});
                        }
                    }
                    
                }
            }
            steps++;
        }
        
        for(int i = 0; i<n;i++){
            if(path[i]==INT_MAX) path[i] = -1 ;
        }
        
        return path;
    }
};