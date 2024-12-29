class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long n = (long)nums.length, count = 0, total = 0;
        for(int i = 0; i < n; i++) 
        {
            if(nums[i] == 0) {
                count++;
                total += count;
            }
            else count = 0;
        }

        return total;
    }
}