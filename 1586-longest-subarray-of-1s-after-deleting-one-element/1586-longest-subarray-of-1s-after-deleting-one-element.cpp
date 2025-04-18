class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);

        int s = 0;
        for(int i = n-1; i >= 0; i--) {
            s += nums[i];
            if(nums[i] == 0) s = 0;

            v[i] = s;
        }

        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

        int mx = 0, ls = 0;
        for(int i = 0; i < n; i++) 
        {
            int rs;
            if(i == n-1) {
                rs = 0;
            }
            else rs = v[i+1];

            mx = max(mx, ls + rs);
            
            ls += nums[i];
            if(nums[i] == 0) {
                ls = 0;
            }
        }

        return mx;
    }
};

/*

1111011010011010101011110
1234012010012010101012340
4321021010021010101043210
*/