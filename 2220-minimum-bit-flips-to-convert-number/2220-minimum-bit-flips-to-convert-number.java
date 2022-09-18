class Solution {
    public int minBitFlips(int n1, int n2) {
        int s = 0;
        while(n1 != 0 && n2 != 0)
        {
            int x = n1 % 2;
            int y = n2 % 2;

            if(x != y) s++;

            n1 /= 2;
            n2 /= 2;
        }	

        while(n1 != 0) 
        {
            int x = n1 % 2;
            if(x == 1) s++;

            n1 /= 2;
        }

        while(n2 != 0) {
            int x = n2 % 2;
            if(x == 1) s++;

            n2 /= 2;
        }
        
        return s;
    }
}