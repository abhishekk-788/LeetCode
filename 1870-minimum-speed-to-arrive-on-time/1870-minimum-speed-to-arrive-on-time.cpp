class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int n = dist.size();
        
        int l = 1, r = 1e9, ans = INT_MAX;
        while(l <= r)
        {
            double tt = 0.0;
            int mid = l + (r-l)/2;
            
            for(int i = 0; i < n-1; i++)
            {
                tt += ceil((dist[i] * 1.0) / mid);
            }
            tt += ((dist[n-1] * 1.0) / mid);
            
            if(tt <= hour)
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid+1;
        }
        
        return ans == INT_MAX ? -1: ans;
    }
};