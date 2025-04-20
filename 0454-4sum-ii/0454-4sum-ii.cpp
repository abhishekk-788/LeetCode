class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int, int> mp;

        int n1 = nums1.size(), n2 = nums2.size(), n3 = nums3.size(), n4 = nums4.size(); 
        for(int i = 0; i < n1; i++) 
        {
            for(int j = 0; j < n2; j++) {
                int s = nums1[i] + nums2[j];
                mp[s]++;
            }
        } 

        int ans = 0;   
        for(int i = 0; i < n3; i++) 
        {
            for(int j = 0; j < n4; j++) {
                int s = nums3[i] + nums4[j];
                int cnt = mp[-s];

                ans += cnt;
            }
        }

        return ans;
    }
};

/*

i + j + k + l = 0
i + j = -(k + l)


*/