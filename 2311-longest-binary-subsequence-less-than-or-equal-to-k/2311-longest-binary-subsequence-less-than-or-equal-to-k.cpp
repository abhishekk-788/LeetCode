#define ll long long
class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        ll n = s.length(), i = n-1, cnt = 0, val = (ll)k;
        while(i >= 0)
        {
            ll xx = s[i] == '0' ? 0: 1;
            if(cnt >= 31) break;
            
            val = val - (xx << cnt);
            if(val < 0) break;
            
            cnt++; i--;
        }
        while(i >= 0) 
        {
            if(s[i] == '0') cnt++;
            i--;
        }
        
        return cnt;
        
    }
};