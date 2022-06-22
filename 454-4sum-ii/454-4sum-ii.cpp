class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int count = 0;
        unordered_map<int, int> neg;
        
        for(int i : nums1)
        {
            for(int j : nums2)
            {
                int sum = i + j;
                neg[sum]++;
            }
        }
        
        for(int k : nums3)
        {
            for(int l : nums4)
            {
                int sum = k + l;
                count += neg[-sum];
            }
        }
        
        return count;    
    }
};