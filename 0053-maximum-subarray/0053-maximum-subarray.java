class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int s = nums[0], mxSum = s;

        for(int i = 1; i < n; i++) 
        {
            s += nums[i];
            if(nums[i] > s) {
                s = nums[i];
            }
            mxSum = Math.max(s, mxSum);

            // System.out.println(s + " " + mxSum);
        }

        return mxSum;
    }
}