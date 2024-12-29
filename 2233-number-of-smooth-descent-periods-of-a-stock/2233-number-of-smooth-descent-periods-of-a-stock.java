class Solution {
    public long getDescentPeriods(int[] prices) 
    {
        long n = prices.length, count = 1, prev = 1;
        for(int i = 1; i < n; i++) 
        {
            if(prices[i-1] - prices[i] == 1) {
                prev++;
            }
            else prev = 1;

            count += prev;
        }    
        return count;
    }
}

/*

5 4 3 2 1

*/