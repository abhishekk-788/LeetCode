class Solution {
public:
    string maximumBinaryString(string s) {
        int zeros = 0, i = 0, len = s.size();
        while (s[i] == '1')  {
            i++;
        } 
        for (int j = i; j < len; j++) 
        {
            zeros += s[j] == '0';
        }
        if (zeros < 2) 
            return s;

        while (--zeros) { 
            s[i++] = '1';
        }
        s[i++] = '0';
        
        while (i < len) {
            s[i++] = '1';
        }
        
        return s;
    }
};

/*

010010001010
101

010
101

000
110





000110
100110
110110
110101
110011
111011

*/