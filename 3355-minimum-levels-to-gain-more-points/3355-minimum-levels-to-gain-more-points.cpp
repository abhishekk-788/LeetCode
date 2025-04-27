class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size(), s = 0;
        for(int i = 0; i < n; i++) {
            if(possible[i] == 0) s += -1;
            else s += 1;
        }

        int curr = 0;
        for(int i = 0; i < n; i++)
        {
            if(possible[i] == 0) curr += -1;
            else curr += 1;

            if(curr > (s - curr)) {
                return i+1;
            } 
        }

        return -1;
    }
};