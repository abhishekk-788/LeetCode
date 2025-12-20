class Solution {
public:
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string, int> dict;
        int i, j;
        int ans = 0;
        
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        
        for (i = 0; i < words.size(); i++) 
        {
            int count = 0;
            for (j = 0; j < words[i].size(); j++) 
            {
                string tmp = words[i].substr(0, j) + words[i].substr(j + 1);
                if (tmp != "") {
                    count = max(count, dict[tmp]);
                }
            }
            dict[words[i]] = count + 1;
            ans = max(ans, count + 1);
        }
        return ans;
        
    }
};