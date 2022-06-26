class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size(), s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++) {
            s1 += nums1[i]; s2 += nums2[i]; 
        }
        
        // cout << s1 << " " << s2 << "\n";
        
        int sm1 = 0, sm2 = 0, ans1 = INT_MIN, ans2 = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            sm1 += nums2[i] - nums1[i];
            sm2 += nums1[i] - nums2[i];
            
            if(sm1 < nums2[i] - nums1[i]) {
                sm1 = nums2[i] - nums1[i];
            }
            if(sm2 < nums1[i] - nums2[i]) {
                sm2 = nums1[i] - nums2[i];
            }
            
            ans1 = max(sm1, ans1);
            ans2 = max(sm2, ans2);
            
            // cout << sm1 << " " << sm2 << " " << ans1 << " " << ans2 << "\n";

        }
        
        return max(s1 + ans1, s2 + ans2);
    }
};

/*

[28,34,38,14,30,31,23,7,28,3] = 
[42,35,7,6,24,30,14,21,20,34] = 

*/