class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;

        int n = nums.size();
        int t = (1 << n);

        for(int i = 0; i < t; i++)
        {
            vector<int> vec;
            for(int j = 0; j < n; j++)
            {
                if((1 << j) & i) {
                    vec.push_back(nums[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};