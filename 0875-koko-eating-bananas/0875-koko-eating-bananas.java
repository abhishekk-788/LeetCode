class Solution {
    public int minEatingSpeed(int[] piles, int h) 
    {
        long sum = 0, n = piles.length;
        for(int i = 0; i < n; i++) {
            sum += piles[i];
        }    

        long l = 1, r = sum;
        long ans = r;
        while(l <= r) 
        {
            long mid = l + (r-l)/2;
            long hours = 0;
            for(int i = 0; i < n; i++)
            {
                hours += (long)Math.ceil((double)piles[i]/mid);
            }
            if(hours <= h) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return (int)ans;
    }
}

/*


*/