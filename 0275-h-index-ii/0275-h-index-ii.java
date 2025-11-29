class Solution {
    public int hIndex(int[] citations) 
    {
        int n = citations.length, l = 0, r = n-1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(mid + 1 > citations[n - mid - 1]) {
                r = mid - 1;
            }
            else 
            {
                l = mid + 1;
            }
        }    
        return l;
    }
}

/*

[0,1,3,5,6]

[1, 2, 100, 100]

(2 -> (n-))

*/