class Solution {
public:
    string ans;
    void F(string str, int n, int &k, char prev)
    {
        if(k == 0) return;
        if(n == 0)
        {   
            k--;
            
            if(k == 0) ans = str;
            return;
        }
        for(char i = 'a'; i <= 'c'; i++)
        {
            if(prev != i)
            {
                F(str + i, n-1, k, i);
            }
        }
    }
    
    string getHappyString(int n, int k) 
    {
        string str = ""; ans = "";
        char prev = '0';
        
        F(str, n, k, prev);
        return ans;
    }
};

/*

aba
abc
aca

*/