class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) 
    {
        long long x = 0, y = 0, n = text.length(), cnt1 = 0, cnt2 = 0;
        string s1 = pattern[0] + text, s2 = text + pattern[1];
        
        for(int i = 0; i <= n; i++)
        {
            if(s1[i] == pattern[1]) {
                cnt1 += x;
            }
            if(s1[i] == pattern[0]) {
                x++;
            }
        }
        
        for(int i = 0; i <= n; i++)
        {
            if(s2[i] == pattern[1]) {
                cnt2 += y;
            }
            if(s2[i] == pattern[0]) {
                y++;
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