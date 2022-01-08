class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0, n = nums.size();
        for(int i = 0; i < 32; i++)
        {
            int x = 1 << i;
            
            int sum = 0;
            for(int j = 0; j < n; j++)
            {
                if(x & nums[j]) sum++;
            }

            if(sum % 3) res = res | x;
        }
        
        return res;
    }
};

/*

2 2 3 2

010
010
011
010
001
001
001


*/