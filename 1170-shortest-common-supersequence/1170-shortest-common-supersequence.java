class Solution {
    public String shortestCommonSupersequence(String s1, String s2) 
    {
        int l1 = s1.length(), l2 = s2.length();
        int[][] dp = new int[l1+1][l2+1];

        for(int i = 1; i <= l1; i++)
        {
            for(int j = 1; j <= l2; j++)
            {
                if(s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i = l1, j = l2;
        StringBuilder lcs = new StringBuilder();

        while(i > 0 && j > 0)
        {
            if(s1.charAt(i-1) == s2.charAt(j-1)) {
                lcs.append(s1.charAt(i-1));
                i--; j--;
            }
            else if(dp[i-1][j] < dp[i][j-1]) {
                lcs.append(s2.charAt(j-1));
                j--;
            }
            else {
                lcs.append(s1.charAt(i-1));
                i--;
            }
        }

        while(i > 0) {
            lcs.append(s1.charAt(i-1));
            i--;
        }
        while(j > 0) {
            lcs.append(s2.charAt(j-1));
            j--;
        }
        
        lcs.reverse();
        
        
        return lcs.toString();
    }
}

/*

    c a b
  0 0 0 0
a 0 0 1 1
b 0 0 1 2
a 0 0 1 2
c 0 0 1 2

*/