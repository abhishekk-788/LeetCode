class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        if(l == r) return 0;
        
        long long res = f(nums, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(nums, cost, x), y2 = f(nums, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }

    long long f(vector<int>& nums, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i)
            res += 1L * abs(nums[i] - x) * cost[i];
        return res;
    }
};