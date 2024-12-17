class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {   
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> dist(r, vector<int> (c, 1e9));
        
        dist[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!pq.empty()) 
        {
            auto itr = pq.top();
            pq.pop();
            
            int wt = itr[0];
            int x = itr[1], y = itr[2];
            
            for (vector<int> dir: directions)
            {
                int xx = x + dir[0];
                int yy = y + dir[1];
                
                if (xx >= 0 && xx < r && yy >= 0 && yy < c)
                {
                    int a = heights[x][y];
                    int b = heights[xx][yy];
                    
                    int effort = max(dist[x][y], abs(a - b));
                    
                    if (dist[xx][yy] > effort)
                    {
                        dist[xx][yy] = effort;
                        pq.push({effort, xx, yy});
                    }
                }
            }
        }
        
        return dist[r-1][c-1];
    }
};