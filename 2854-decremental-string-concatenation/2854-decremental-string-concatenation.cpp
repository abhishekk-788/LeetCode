class Solution {
public:
    int dp[1001][26][26];
    int helper(int i, int f, int s, vector<string>& words) {
        if(i == words.size()) {
            return 0;
        }
        if(dp[i][f][s] != -1) {
            return dp[i][f][s];
        }

        int front = INT_MAX, back = INT_MAX;
        int ff = words[i][0] - 'a', ss = words[i][words[i].size() - 1] - 'a';
        if(s == ff) {
            back = words[i].size() - 1 + helper(i + 1, f, ss, words);
        }
        else {
            back = words[i].size() + helper(i + 1, f, ss, words);
        }

        if(ss == f) {
            front = words[i].size() - 1 + helper(i + 1, ff, s, words);
        }
        else {
            front = words[i].size() + helper(i + 1, ff, s, words);
        }

        return dp[i][f][s] = min(front, back);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp, -1, sizeof(dp));
        return words[0].size() + helper(1, words[0][0] - 'a', words[0][words[0].size() - 1] - 'a', words);
    }
};