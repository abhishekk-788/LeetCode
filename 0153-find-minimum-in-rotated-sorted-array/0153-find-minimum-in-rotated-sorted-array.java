class Solution {
    public int findMin(int[] nums) 
    {
        int ans = nums[0];
        int n = nums.length;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else { 
                r = mid;
            }
        }
        return nums[l];
    }
}

// [3,4,5,1,2]

