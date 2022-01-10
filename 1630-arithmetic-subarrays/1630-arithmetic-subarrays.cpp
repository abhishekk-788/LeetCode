class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int q = l.size(), n = nums.size();
        
        vector<bool> res(q, true);
        for(int i = 0; i < q; i++)
        {
            int lt = l[i], rt = r[i];
            
            vector<int> vec;
            for(int j = lt; j <= rt; j++) vec.push_back(nums[j]);
            
            sort(vec.begin(), vec.end());
            for(int j = 2; j < vec.size(); j++)
            {
                if(vec[j] - vec[j-1] != vec[j-1] - vec[j-2])
                {
                    res[i] = false;
                    break;
                }
            }
        }
        
        return res;
    }
};