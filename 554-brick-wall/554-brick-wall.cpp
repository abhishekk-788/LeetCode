class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) 
    {
        int n = wall.size();
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++)
        {
            if(wall[i].size() > 1) mp[wall[i][0]]++;
            for(int j = 1; j < wall[i].size()-1; j++)
            {
                wall[i][j] += wall[i][j-1];
                 mp[wall[i][j]]++;
            }
        }
        
        int ans = n;
        for(auto itr: mp)
        {
            // cout << itr.first << " " << itr.second << "\n";
            ans = min(ans, n - itr.second);
        }
        
        return ans;
    }
};