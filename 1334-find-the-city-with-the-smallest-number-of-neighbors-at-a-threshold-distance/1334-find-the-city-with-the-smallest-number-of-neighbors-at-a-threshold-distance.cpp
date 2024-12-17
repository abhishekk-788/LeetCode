class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < edges.size(); i++) {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
    
        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) { 
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        
        int mnReachables = n-1, ans = -1;
        for (int i = 0; i < n; i++) 
        {
            int reachableNodesCount = 0;
            for (int j = 0; j < n; j++) 
            {
                if(i != j && matrix[i][j] != 1e9 && matrix[i][j] <= distanceThreshold) {
                    reachableNodesCount++;
                }
            }
            if(reachableNodesCount == mnReachables) {
                ans = max(ans, i);
            }
            if(reachableNodesCount < mnReachables) 
            {
                ans = i;
                mnReachables = reachableNodesCount;
            }
        }
        
        return ans;
    }
};