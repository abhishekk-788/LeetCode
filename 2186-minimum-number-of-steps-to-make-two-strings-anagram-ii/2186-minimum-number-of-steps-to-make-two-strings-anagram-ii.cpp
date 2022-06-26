class Solution {
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char, int> mp;
        int n = s.size(), m = t.size();

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        for(int i = 0; i < m; i++) {
            mp[t[i]]--;
        }
        
        int cnt = 0;
        for(auto i: mp) {
            cnt += abs(i.second);
        }
        
        return cnt;
    }
};

/*

leetcode   coats

*/