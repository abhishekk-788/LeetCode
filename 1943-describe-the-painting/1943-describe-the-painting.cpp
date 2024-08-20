class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        map<long long, long long> hash;
        vector<vector<long long>> res;
        
        for(auto s: segments) {
            hash[(long long)s[0]] += (long long)s[2];
            hash[(long long)s[1]] -= (long long) s[2];
        }
        
        long long i = 0, s = 0;
        for(auto m: hash) {
            long long prev = s;
            s += m.second;
            
            if(prev > 0) {
                res.push_back({i, m.first, prev});
            }
            i = m.first;
        }
        
        return res;
    }
};

/*

1 4 5  4 7 7   => 1 4 5  4 7 7
1 4 5. 2 7 7   => 1 2 5  2 5 12  5 7 7
1 4 5. 2 3 7   => 1 2 5  2 3 12  3 4 5
1 4 5  2 5 7   => 1 


1 5  1 9    => 1 14
4 -5  4 7   => 4 2
7 -7  7 -9  => 7 -16

*/