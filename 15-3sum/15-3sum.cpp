class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        vector<vector<int>> res;  
        sort(arr.begin(), arr.end());
        
        int n = arr.size(), K = 0; 
        for(int i = 0; i < n; i++)
        {
            int ele = arr[i];
            int x = K - arr[i];

            if(i > 0 && arr[i] == arr[i-1]) continue;

            int l = i+1, r = n-1;
            while(l < r)
            {
                if(arr[l] + arr[r] == x)
                {
                    res.push_back({ele,arr[l],arr[r]});
                    l++;
                    r--;

                    while(l < r && l > 0 && r < n-1 && arr[l] == arr[l-1] && arr[r] == arr[r+1]) {
                        l++; r--;
                    }
                }
                else if(arr[l] + arr[r] < x) l++;
                else r--;
            }
        }
        return res;
    }
};