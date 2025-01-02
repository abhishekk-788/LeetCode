class Solution {
    public int minInsertions(String s)
    {
        int n = s.length();
        
        StringBuilder str1 = new StringBuilder(s);
        StringBuilder str2 = new StringBuilder(s);

        int l1 = str1.length(), l2 = str2.length();
        int[][] dp = new int[l1+1][l2+1];

        str2.reverse();

        for(int i = 0; i <= l1; i++) {
            for(int j = 0; j <= l2; j++) {
                dp[i][j] = 0;
            }
        }

        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return n - (int)dp[l1][l2];
    }
}

/*

leedtcocotdee

*/