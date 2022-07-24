class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size(), q = queries.size();
        vector<int> ans(q);
        
        for(int i = 0; i < q; i++)
        {
            int x = queries[i][0], y = queries[i][1];
            vector<pair<string, int>> vii;
            
            for(int k = 0; k < n; k++) {
                vii.push_back({(nums[k].substr(nums[k].size()-y)), k});
            }
        
            sort(vii.begin(), vii.end());
            ans[i] = vii[x-1].second;
        }
        
        return ans;
    }
};