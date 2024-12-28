class Solution {
    public int monotoneIncreasingDigits(int n) {
        String str = String.valueOf(n);
        int len = str.length();

        char[] digits = str.toCharArray();
        int pos = -1;

        for (int i = len - 1; i > 0; i--) {
            if (digits[i - 1] > digits[i]) {
                digits[i - 1]--;
                pos = i;
            }
        }

        if (pos == -1) return n;
        for (int i = pos; i < len; i++) {
            digits[i] = '9';
        }

        return Integer.parseInt(new String(digits));
    }
}
