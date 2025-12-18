class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), sz = 1;
        vector<int> vec;

        vec.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] > vec[sz - 1]) {
                vec.push_back(nums[i]);
                sz++;
            }
            else
            {
                int l = 0, r = sz - 1, idx = -1;
                while(l <= r) {
                    int mid = l + (r - l) / 2;
                    if(nums[i] <= vec[mid]) {
                        idx = mid;
                        r = mid - 1;
                    }
                    else l = mid + 1;
                }

                vec[idx] = nums[i];
            }

            // for(auto ele: vec) {
            //     cout << ele << " ";
            // }
            // cout << "\n";
         }
        return sz;
    }
};