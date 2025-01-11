class Solution {
public:
    int binarySearch(vector<int>& arr, int target) 
    {
        int low = 0, high = arr.size() - 1, result = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) 
    {
        int n = coins.size();
        sort(coins.begin(), coins.end()); 
        
        vector<long long> prefix(coins.size() + 1, 0); 
        vector<int> starts(n), ends(n);

        for (int i = 0; i < n; i++) 
        {
            starts[i] = coins[i][0];
            ends[i] = coins[i][1];
            
            prefix[i + 1] = prefix[i] + 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        long long ans = 0;

        // First loop: Treat each coin-containing interval as the start of the k-length interval
        for (int i = 0; i < n; i++) {
            long long curr = 0;

            int s = coins[i][0], target = s + k - 1;
            int j = binarySearch(ends, target);
            
            curr += 1LL * (prefix[j] - prefix[i]);
            if (j < n) {
                curr += 1LL * max(0, target - coins[j][0] + 1) * coins[j][2]; 
            }
            ans = max(curr, ans);
        }

        // Second loop: Treat each coin-containing interval as the end of the k-length interval
        for (int i = 0; i < n; i++) 
        {
            long long curr = 0;
            int s = coins[i][1], target = s - k + 1;
            int j = binarySearch(starts, target);

            curr += 1LL * (prefix[i + 1] - prefix[j]);
            if (j > 0) { 
                curr += 1LL * max(0, coins[j - 1][1] - target + 1) * coins[j - 1][2]; // Handle partial overlap
            }
            ans = max(curr, ans);
        }

        return ans;
    }
};


/*

2 2 2 0 4 4 0 1 1
2 4 6 6 10 14 14 15 16

1 -> 2
3 -> 6
5 -> 10
6 -> 14
8 -> 15
10 -> 16

*/