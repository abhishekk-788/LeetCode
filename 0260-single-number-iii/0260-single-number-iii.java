class Solution {
    public int[] singleNumber(int[] nums) 
    {
        int xorValue = 0;
        for(int num: nums) {
            xorValue ^= num;
        }

        int rightMostSetBitPosition = xorValue & (-xorValue);
        
        int[] res = new int[2];
        for(int num: nums) {
            if((rightMostSetBitPosition & num) == 0) {
                res[0] ^= num;
            }
            else res[1] ^= num;
        }

        return res;
    }
}

/*

011
101

110
011
*/