class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        vector<pair<int, int>> vec;
        
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) 
        {
            int j = i;
            if(vec.empty() || vec.back().first > nums[i]) {
                vec.push_back({nums[i], i});
            }
            else 
            {
                int l = 0, r = vec.size();
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    if(nums[i] >= vec[mid].first)
                    {
                        r = mid-1;
                        j = vec[mid].second;
                    }
                    else l = mid+1;
                }
            }
            
            // cout << i << " " << j << "\n";
            ans = max(ans, i-j);
        }
        
        return ans;
        
    }
};

/*

6 0 8 2 1 5

6 0
0 1


6 5 4 3 2 1

9 8 1 0 1 9 4 0 4 1


*/