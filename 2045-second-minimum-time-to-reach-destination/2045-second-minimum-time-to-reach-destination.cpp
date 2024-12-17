class Solution {
public:
    int best = -1, secondBest = -1;
    unordered_map<int, vector<int>> G;
    
    int calculateWaitTime(int currTime, int change) 
    {
        int signalCycle = currTime % (2 * change);
        if (signalCycle >= change) {
            return (2 * change - signalCycle);
        }
        return 0;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        for (auto& edge : edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }

        vector<int> best(n + 1, INT_MAX), secondBest(n + 1, INT_MAX);
        queue<pair<int, int>> q;

        q.push({1, 0});
        best[1] = 0;

        while (!q.empty()) 
        {
            auto [node, currTime] = q.front();
            q.pop();

            for (auto& neighbor : G[node]) 
            {
                int waitTime = calculateWaitTime(currTime, change);
                int arrivalTime = currTime + time + waitTime;

                if (arrivalTime < best[neighbor]) 
                {
                    secondBest[neighbor] = best[neighbor];
                    best[neighbor] = arrivalTime;
                    q.push({neighbor, arrivalTime});
                } else if (arrivalTime > best[neighbor] && arrivalTime < secondBest[neighbor]) 
                {
                    secondBest[neighbor] = arrivalTime;
                    q.push({neighbor, arrivalTime});
                }
            }
        }

        return secondBest[n];
    }
};

/*

If minimum takes -> n edges
Then check if n+1 edges answer is present

5
time = 3
change = 5


time = 24, change = 3

7
[[1,2],[1,3],[2,5],[2,6],[6,5],[5,7],[3,4],[4,7]]
4
7

*/