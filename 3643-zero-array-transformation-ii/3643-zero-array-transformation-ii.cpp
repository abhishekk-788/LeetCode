class Solution 
{
    bool valid(vector<int> nums, vector<vector<int>>& queries, int k){
        vector<int> pre(nums.size(), 0);
        for(int i = 0; i < k; i++) 
        {
            int l = queries[i][0], h = queries[i][1], val = queries[i][2];
            pre[l] -= val;
            if(h + 1 < nums.size()) {
                pre[h+1] += val;
            }
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) 
        {
            sum += pre[i];
            if(nums[i] + sum > 0) {
                return false;
            }
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int low = 0, high = m; 
        while(low <= high) {
            int mid = (low + high) / 2;
            if(valid(nums, queries, mid)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low > m ? -1: low;
    }
};