class Solution {
    public int trap(int[] height) {
        int n = height.length;

        int[] left = new int[n];
        int[] right = new int[n];
        
        left[0] = height[0];
        for(int i = 1; i < n; i++)
        {
            left[i] = Math.max(left[i-1], height[i]);
        }
        
        right[n-1] = height[n-1];
        for(int i = n-2; i >=0; i--)
        {
            right[i] = Math.max(right[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            System.out.print(left[i] + " ");
        }
        System.out.println();
        for(int i = 0; i < n; i++){
            System.out.print(right[i] + " ");
        }
        System.out.println();

        int trapped_water = 0;
        for(int i = 1; i < n-1; i++)
        {
            trapped_water += Math.min(left[i], right[i]) - height[i];
        }
        
        return trapped_water;    
    }
}

/*

[0,1,0,2,1,0,1,3,2,1,2,1]
[0,1,1,2,2,2,2,3,3,3,3,3]
[3,3,3,3,3,3,3,3,2,2,2,1]

*/
