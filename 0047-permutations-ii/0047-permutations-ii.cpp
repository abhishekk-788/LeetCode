class Solution {
public:
    void solve(int i, int n, vector<int> &nums, vector<vector<int>> &res)
    {
        if(i == n){
            res.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for(int j = i; j < n; j++) {
            if(seen.count(nums[j])) continue;
            seen.insert(nums[j]);

            swap(nums[i], nums[j]);
            solve(i + 1, n, nums, res);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        solve(0, n, nums, res);

        return res;
    }
};