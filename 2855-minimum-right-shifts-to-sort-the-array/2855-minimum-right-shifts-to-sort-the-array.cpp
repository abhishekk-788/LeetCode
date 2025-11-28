class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int breakPoint = -1;
        int n = nums.size();
        if(n == 1) return 0;
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                if(breakPoint == -1) {
                    breakPoint = i;
                } else return -1;
            } 
        }
        if(breakPoint == -1) return 0;
        if(nums[n - 1] > nums[0]) return -1; 
        return n - breakPoint - 1;
    }
};