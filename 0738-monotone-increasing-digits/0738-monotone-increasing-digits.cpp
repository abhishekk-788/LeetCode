class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string str = to_string(n);
        int l = str.length();

        int pos = -1;

        for(int i = l-1; i > 0; i--)
        {
            if(str[i-1] > str[i]) {
                str[i-1] -= 1;
                pos = i;
            }
        }

        if(pos == -1) return n;
        for(int i = pos; i < l; i++) {
            str[i] = '9';
        }

        return stoi(str);
    }
};