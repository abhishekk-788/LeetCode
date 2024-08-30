class Solution {
public:
    int F(string s, int x, int y)
    {
        int cnt = 0;
        while(x >= 0 && y < s.length() && s[x] == s[y])
        {
            cnt++;
            
            x--;
            y++;
        }
        return cnt;
    }
    int countSubstrings(string s) 
    {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            int x = F(s, i, i);
            int y = F(s, i, i+1);
            
            cnt += (x + y);
        }
        
        return cnt;
    }
};

/*

abbajkjiuurruui



*/