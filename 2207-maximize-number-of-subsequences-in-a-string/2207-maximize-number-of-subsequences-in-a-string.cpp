class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) 
    {
        long long x = 0, y = 0, n = text.length(), cnt1 = 0, cnt2 = 0;
        string s1 = pattern[0] + text, s2 = text + pattern[1];
        
        if(pattern[0] == pattern[1]) {
            int cnt = 0;
            for(int i = 0; i <= n; i++)
            {
                if(s1[i] == pattern[0]) cnt++;
            }
            
            long long x = cnt * 1LL * (cnt-1);
            x = x / 2LL;
            
            return x;
        }
        
        for(int i = 0; i <= n; i++)
        {
            if(s1[i] == pattern[0]) {
                x++;
            }
            else if(s1[i] == pattern[1]) {
                cnt1 += x;
            }
        }
        
        for(int i = 0; i <= n; i++)
        {
            if(s2[i] == pattern[0]) {
                y++;
            }
            else if(s2[i] == pattern[1]) {
                cnt2 += y;
            }
        }
        
        return max(cnt1, cnt2);
    }
};

/*
accaac

yyyy

yy


*/