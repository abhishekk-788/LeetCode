class Solution {
public:
    int dp[100005][5];
    int bs(vector<vector<int>>& events, int i, int n) 
    {
        int ans = INT_MAX;
        int start = i+1, end = n-1;
        
        while(start <= end) 
        {
            int mid = start + (end - start) / 2;
            if(events[mid][0] > events[i][1])
            {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else start = mid + 1;
        }
        
        return ans;
    }
    int solve(vector<vector<int>>& events, int i, int n, int limit)
    {
        if(i == n || limit == 0) return 0;
        if(dp[i][limit] != -1) return dp[i][limit];
        
        int validIdx = bs(events, i, n);
        
        int mx = 0;
        if(validIdx != INT_MAX) mx = max(mx, events[i][2] + solve(events, validIdx, n, limit-1));
        mx = max(mx, solve(events, i+1, n, limit));
        
        return dp[i][limit] = max(mx, events[i][2]);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));
        
        int n = events.size();
        return solve(events, 0, n, 2);
    }
};

/*

[[1,3,2],[2,4,3],[4,5,2]]

[1,3,2],[1,5,5],[4,5,2]]

*/