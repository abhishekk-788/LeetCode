class Solution {
public:
    int F(string word, int n, char ch)
    {
        if(n <= 0) return 0;
        int x = abs(word[n-1] - ch);
        // cout << n << " " << x << " " << word[n-1] << " " << ch << "\n";
        if(x <= 1) 
        {
            int x = (n >= 2) ? 1 + F(word, n-2, word[n-2]): 1 + F(word, n-1, word[n-1]);
            return x;
        }
        
        return F(word, n-1, word[n-1]);
    }
    int removeAlmostEqualCharacters(string word) 
    {
        int len = word.length();
        return F(word, len-1, word[len-1]);
    }
};