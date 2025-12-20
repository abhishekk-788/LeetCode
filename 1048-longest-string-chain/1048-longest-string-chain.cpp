class Solution {
public:
    bool isPredecessor(string str1, string str2)
    {
        int n1 = str1.length(), n2 = str2.length(); 
        if(n2 - n1 != 1) return false;
        int i = 0, j = 0;
        while(j < n2)
        {
            if(str1[i] == str2[j]) {
                i++; j++;
            }
            else j++;
        } 
        if(i == n1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(), mx = 1;
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isPredecessor(words[i], words[j])) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    mx = max(mx, dp[j]);
                }
            }
        }
        return mx;
    }
};