class Solution {
public:
    bool canConvertString(string s, string t, int k) 
    {
        if(s.length() != t.length()) return false;
        
        int n = s.length();
        unordered_map<int, int> mp;
        
        
        int sm = 0;
        for(int i = 0; i < n; i++)
        {
            char x = s[i];
            char y = t[i];
            
            int d;
            if(y >= x) 
            {
                d = (int)y - (int)x;
            }
            else {
                // cout << (int)y << " " << (int)x << "\n";
                d = 122 - (int)x + (int)y - 97 + 1;
            }
            
            if(mp.count(d) == 1) 
            {
                sm = max(sm, d + 26 * mp[d]);
                mp[d]++;
            }
            else if(d != 0)
            {
                sm = max(sm, d);
                mp[d]++;
            }
            
            if(sm > k) return false;
            // cout << d << " " << sm << "\n";
        }
        
        return true;    
    }
};