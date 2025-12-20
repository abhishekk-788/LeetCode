class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , [](const vector<int>& a , const vector<int>& b){
            return a[1] < b[1];
        });
        int prev = INT_MIN, count = 0;
        for(int i = 0, n = pairs.size(); i < n; ++i){
            if(pairs[i][0] > prev){
                ++count;
                prev = pairs[i][1];
            }
        }
        return count;
    }
};