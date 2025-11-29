class Solution {
    public int findMin(int[] nums) 
    {
        int ans = nums[0];
        int n = nums.length;

        if(n == 2) return Math.min(nums[0], nums[1]);
    
        int l = 0, r = n-1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(nums[mid] >= nums[0] && nums[mid] >= nums[n-1]) {
                l = mid + 1;
            }
            else if(nums[mid] <= nums[0] && nums[mid] <= nums[n-1]) {
                ans = nums[mid];
                r = mid - 1;
            }
            else {
                r = mid - 1;
            }

            System.out.println(l + " " + r);
        } 
        return ans;
    }
}

// [3,4,5,1,2]

