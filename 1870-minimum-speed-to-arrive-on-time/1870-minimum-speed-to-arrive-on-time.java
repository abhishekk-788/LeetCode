class Solution 
{
    public int minSpeedOnTime(int[] dist, double hour) {
        int n = dist.length;

        int l = 1, r = (int) 1e9, ans = Integer.MAX_VALUE;
        while (l <= r) 
        {
            double tt = 0.0;
            int mid = l + (r - l) / 2;

            for (int i = 0; i < n - 1; i++) {
                tt += Math.ceil(dist[i] * 1.0 / mid);
            }
            
            tt += (dist[n - 1] * 1.0 / mid);
            
            if (tt <= hour) {
                ans = Math.min(ans, mid);
                r = mid - 1;
            } 
            else l = mid + 1;
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
