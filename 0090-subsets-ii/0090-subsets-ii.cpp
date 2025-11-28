class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int i, int n, vector<int> &vec)
    {
        if(i == n) {
            res.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        solve(nums, i+1, n, vec);
        vec.pop_back();
        int idx = i+1;
        while(idx < n && nums[i] == nums[idx]) {
            idx++;
        }
        solve(nums, idx, n, vec);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;

        sort(nums.begin(), nums.end());
        solve(nums, 0, n, vec);

        return res;
    }
};