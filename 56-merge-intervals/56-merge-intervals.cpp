class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        int x = intervals[0][0], y = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] <= y)
            {
                y = max(y, intervals[i][1]);
            }
            else
            {
                res.push_back({x, y});
                x = intervals[i][0]; y = intervals[i][1];
            }
        }
        
        res.push_back({x, y});
        return res;
    }
};

/*

1 3


*/