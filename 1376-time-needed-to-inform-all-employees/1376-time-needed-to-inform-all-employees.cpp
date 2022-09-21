class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        map<int, vector<int>> G;
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) G[manager[i]].push_back(i);
        }
        
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        
        int ans = 0;
        
        q.push({headID, 0});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int x = p.first, s = p.second;
            ans = max(ans, s);
            
            if(vis[x] == 0)
            {
                vis[x] = 1;
                for(int i = 0; i < G[x].size(); i++) {
                    q.push({G[x][i], s+informTime[x]});
                }
            }
        }
        
        return ans;
    }
};

/*

    [2,2,-1,2,2,2]
    [2, -1, 1]
    
    
     1
    /
   2
  /
 0
 
 
*/