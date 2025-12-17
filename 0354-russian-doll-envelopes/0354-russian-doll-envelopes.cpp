class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n = envelopes.size();
        if (n == 0) return 0;

        sort(envelopes.begin(), envelopes.end(),
            [](auto &a, auto &b) {
                if (a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
            });

        vector<int> dp;

        for (int i = 0; i < n; i++) {
            int h = envelopes[i][1];
            int l = 0, r = dp.size() - 1, pos = dp.size();

            while (l <= r) 
            {
                int mid = l + (r - l) / 2;
                if (dp[mid] >= h)
                    pos = mid, r = mid - 1;
                else
                    l = mid + 1;
            }

            if (pos == dp.size()) dp.push_back(h);
            else dp[pos] = h;
        }

        return dp.size();
    }
};

/*

    [[5,4],[6,4],[6,7],[2,3]]
    [[2,3],[5,4],[6,4],[6,7]]
  
0 0 0 0
1 3 -1 -1

[[2,100],[3,200],[4,300],[5,250],[5,400],[5,500],[6,360],[6,370],[7,380]]

-1 0 1 1 2 2 3 3 6

1 1 1 1 1 1 1 1 1
1 2 3 3 4 4 4 4 5


*/