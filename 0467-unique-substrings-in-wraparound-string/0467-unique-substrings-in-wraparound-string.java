class Solution {
    public int findSubstringInWraproundString(String s) 
    {
        int[] dp = new int[26];
        int n = s.length(), maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && (s.charAt(i) - s.charAt(i - 1) == 1 || s.charAt(i - 1) - s.charAt(i) == 25)) 
                maxLen++;
            else maxLen = 1;
            
            int index = s.charAt(i) - 'a';
            dp[index] = Math.max(dp[index], maxLen);
        }

        int total = 0;
        for (int count : dp) {
            total += count;
        }

        return total;
    }
}

/*


*/