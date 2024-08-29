class Solution {
public:
    int dp[100005][5];
    int bs(vector<int> &pzPos, int start, int end, int value) 
    {
        int ans = start;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(pzPos[mid] <= value) 
            {
                ans = max(ans, mid);
                start = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
    int solve(vector<int> &pzPos, int i, int n, int k, int limit) 
    {
        if(i == n || limit == 0) return 0;
        if(dp[i][limit] != -1) return dp[i][limit];
        
        int value = pzPos[i] + k;
        
        int pos = bs(pzPos, i, n-1, value);
        
        int take = (pos - i + 1) + solve(pzPos, pos + 1, n, k, limit-1);
        int doNotTake = solve(pzPos, i+1, n, k, limit);
        
        return dp[i][limit] = max(take, doNotTake);
    }
    int maximizeWin(vector<int>& prizePositions, int k) 
    {
        int n = prizePositions.size();
        
        memset(dp, -1, sizeof(dp));
        return solve(prizePositions, 0, n, k, 2);
    }
};

/*

[1,1,2,2,3,3,5]

[1,2,3,4,5]
1


*/