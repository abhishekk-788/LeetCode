class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        queue<int> q;
        
        int prevNum = nums[0], count = 0;
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] <= prevNum) 
            {
                prevNum++;
                count += (prevNum - nums[i]);
            } 
            else {
                prevNum = nums[i];
            }
        }
        return count;
    }
};

/*

3 2 1 2 1 7
1 1 2 2 3 7

1 2 2 3 4 5 6 7 8 9

1 1 1 1 2 2 2 6 7 8
1 2 3 4 5 6 7 8 9 10

0 1 2 3 3 4 5 2 2 2 = 24

*/