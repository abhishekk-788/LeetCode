class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
            
        vector<bool> visited(n, false); 
        int sum = 0, edgesUsed = 0;
        
        while(!pq.empty() && edgesUsed < n)
        {
            auto itr = pq.top();
            
            int wt = itr.first;
            int nodeIndex = itr.second;
            
            pq.pop();
            
            if (visited[nodeIndex]) continue;
            
            visited[nodeIndex] = true;
            edgesUsed++;
            
            sum += wt;
            
            for(int i = 0; i < n; i++)
            {
                if(!visited[i]) {
                    int d = (abs(points[nodeIndex][0] - points[i][0]) + abs(points[nodeIndex][1] - points[i][1]));
                    pq.push({d, i});
                }
            }
        }
        
        return sum;
    }
};

/*

 [[0,0],[2,2],[3,10],[5,2],[7,0]]
 

*/