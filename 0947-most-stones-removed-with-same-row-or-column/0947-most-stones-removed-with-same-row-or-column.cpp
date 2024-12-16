class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) 
    {
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) 
    {
        unordered_map<int, vector<int>> graph;

        int n = stones.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        unordered_set<int> visited;
        int connectedComponents = 0;
        for (int i = 0; i < n; i++) 
        {
            if (visited.find(i) == visited.end()) {
                dfs(i, graph, visited);
                connectedComponents++;
            }
        }

        return n - connectedComponents;
    }
};
