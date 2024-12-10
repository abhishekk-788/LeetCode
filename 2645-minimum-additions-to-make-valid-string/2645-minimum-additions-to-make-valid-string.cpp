class Solution {
public:
    int F(string word, int n, char ch)
    {
        if(n == 0) return 0;
        if(word[n-1] == ch)
        {
            char nxt = (ch == 'c') ? 'b': (ch == 'b') ? 'a': 'c';
            return F(word, n-1, nxt);
        } 
        int add = 0;
        
        if(word[n-1] == 'a' && ch == 'b') add = 1;
        if(word[n-1] == 'a' && ch == 'c') add = 2;
        if(word[n-1] == 'b' && ch == 'a') add = 2;
        if(word[n-1] == 'b' && ch == 'c') add = 1;
        if(word[n-1] == 'c' && ch == 'a') add = 1;
        if(word[n-1] == 'c' && ch == 'b') add = 2;
        
        char nxt = (word[n-1] == 'b') ? 'a': (word[n-1] == 'a') ? 'c': 'b';
        
        return add + F(word, n-1, nxt);
    }
    int addMinimum(string word) 
    {
        int len = word.length();
        int add = (word[0] == 'a') ? 0: (word[0] == 'b') ? 1: 2;
        
        return add + F(word, len, 'c');    
    }
};

/*

a b
a c
b a
b c
c a
c b

"aaaacc"

abcabcabcabcabc

*/