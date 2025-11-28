class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, int n, vector<int> &nums, vector<int> temp)
    {
        if(i == n) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, n, nums, temp);
        temp.pop_back();
        solve(i+1, n, nums, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(0, n, nums, temp);

        return res;
    }
};