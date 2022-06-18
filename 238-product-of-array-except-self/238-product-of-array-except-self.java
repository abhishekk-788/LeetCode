class Solution {
    public int[] productExceptSelf(int[] arr) {
        
        int n = arr.length;
        long p = 1, mod = 100000007;
        
        int[] nums = new int[n];
        for(int i = 0; i < n; i++) {
            p *= arr[i];
            nums[i] = (int)p;
        }
        
        p = 1;
        for(int i = n-1; i > 0; i--)
        {
            long x = (nums[i-1] * p);
            
//          System.out.println(x);
            nums[i] = (int)x;
            
            p *= arr[i];
        }
        
        nums[0] = (int)p;
        
        return nums;
    }
}