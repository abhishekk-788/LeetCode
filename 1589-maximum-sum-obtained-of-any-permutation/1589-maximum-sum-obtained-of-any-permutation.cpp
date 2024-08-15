class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& reqs) 
    {
        int n = nums.size(), r = reqs.size();
        
        sort(reqs.begin(), reqs.end());
        sort(nums.begin(), nums.end());
        
        vector<int> v(n, 0);
        for(int i = 0; i < r; i++)
        {
            v[reqs[i][0]]++;
            if(reqs[i][1] != n-1) {
                v[reqs[i][1] + 1]--;
            }
        }
        
        for(int i = 1; i < n; i++) {
            v[i] += v[i-1];    
        }
        
        sort(v.begin(), v.end());
        
        long long s = 0;
        for(int i = 0; i < n; i++)
        {
            s += (v[i] * 1LL * nums[i]);
            s = (s % 1000000007);
        }
        
        return s;
    }
};

/*

 1 2 -1 -1 -1 -
 
 1 3 2 1 0 0
 
 4 10 5 3 1 2
 
 4 + 30 + 10 + 3 + 0 + 0

*/