class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n = shifts.size();
        shifts[n-1] %= 26;
        for(int i = n-2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        }
        
        for(int i = 0; i < s.length(); i++) {
            int x = s[i] - 97;
            x = (x + shifts[i]) % 26;
            s[i] = char(x + 97);
        }
        
        return s;
    }
};