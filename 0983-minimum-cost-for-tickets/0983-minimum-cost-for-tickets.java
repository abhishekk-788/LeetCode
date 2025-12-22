class Solution {
    int[] dp;
    public int bs(int[] days, int n, int d)
    {
        int l = 0, r = n, curr = days[n], ans = n;
        while(l <= r) 
        {
            int mid = l + (r - l) / 2;
            if(curr - days[mid] < d) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    public int solve(int[] days, int[] costs, int n) {
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];

        int x = costs[0] + solve(days, costs, n-1);
        
        int week = bs(days, n, 7);
        int y = costs[1] + solve(days, costs, week-1);

        int month = bs(days, n, 30);
        int z = costs[2] + solve(days, costs, month-1);

        return dp[n] = Math.min(x, Math.min(y, z));
    }
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        dp = new int[366];

        for(int i = 0; i <= 365; i++) {
            dp[i] = -1;
        }
        return solve(days, costs, n-1);
    }
}