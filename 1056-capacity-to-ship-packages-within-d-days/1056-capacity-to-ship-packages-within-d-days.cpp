class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size(), s = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            s += weights[i];
            mx = max(mx, weights[i]);
        }

        int l = mx, r = s, ans = s;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            int w = 0, cnt = 0;
            for(int i = 0; i < n; i++)
            {
                w += weights[i];
                if(w > mid) 
                {
                    w = weights[i];
                    cnt++;
                }
            }
            if(s > 0) cnt++;

            // cout << mid << " " << cnt << "\n";

            if(cnt <= days) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};