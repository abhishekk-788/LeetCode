class Solution {
    public int garbageCollection(String[] garbage, int[] travel)
    {
        int n = garbage.length, mIndex = -1, pIndex = -1, gIndex = -1;
        for(int i = n-1; i >= 0; i--) {
            if(garbage[i].contains("M") && mIndex == -1) mIndex = i;
            if(garbage[i].contains("P") && pIndex == -1) pIndex = i;
            if(garbage[i].contains("G") && gIndex == -1) gIndex = i;
        }

        for(int i = 1; i < travel.length; i++) {
            travel[i] += travel[i-1];
        }

        int ans = 0;
        if(gIndex > 0) ans += travel[gIndex-1];
        if(mIndex > 0) ans += travel[mIndex-1];
        if(pIndex > 0) ans += travel[pIndex-1];
    
        for(int i = 0;i < n; i++) {
            ans += garbage[i].length();
        }

        return ans;
    }
}

/*


 */