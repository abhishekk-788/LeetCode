class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) 
    {
        unordered_map<int, int> freq;
        map<int, int> line;
        for (const int& n : nums) 
        {
            freq[n]++;
            line[n];
            line[n - k]++;
            line[n + k + 1]--;
        }
        int res = 0, curRes = 0;
        for (auto [cur, cnt] : line) 
        {
            curRes += cnt;
            res = max(res, freq[cur] + min(curRes - freq[cur], numOperations));
        }
        return res;
    }
};

/*

[1, 4, 5]


*/