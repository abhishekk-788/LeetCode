class Solution {
public:
    bool isPallindrome(string x)
    {
        int i = 0, j = x.length()-1;
        while(i < j)
        {
            if(x[i] != x[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    vector<vector<string>> vec;
    void F(int i, string s, string x, vector<string> &str)
    {
        if(i == s.length()) 
        {
            if(x == "")
            {
                vec.push_back(str);
            }
            return;
        }
        
        x += s[i];
        if(isPallindrome(x))
        {
            str.push_back(x);
            F(i+1, s, "", str);
            
            str.pop_back();
        }
        
        F(i+1, s, x, str);
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string> str;
        F(0, s, "", str);    
        
        return vec;
    }
};