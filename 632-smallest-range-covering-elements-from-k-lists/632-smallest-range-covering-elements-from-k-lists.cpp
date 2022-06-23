typedef pair<int, int> pi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int n = nums.size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;   
        
        int mx = 0, mn = INT_MAX;
        vector<int> pos(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            pq.push({nums[i][0], i});
            
            mx = max(mx, nums[i][0]);
            mn = min(mn, nums[i][0]);
        }
        
        int ans = mx - mn;
        int mx_ans = mx, mn_ans = mn;
        
        while(!pq.empty())
        {
            pi p = pq.top();
            pq.pop();
            
            int x = p.first, y = p.second;
            pos[y]++;
            
            if(pos[y] == nums[y].size()) break;
            
            int new_val = nums[y][pos[y]];
            
            pq.push({new_val, y});
            
            mx = max(mx, new_val);
            mn = pq.top().first;
            
            if(mx - mn < ans)
            {
                mx_ans = mx;
                mn_ans = mn;
                
                ans = mx - mn;
            }
        }
        
        return {mn_ans, mx_ans};
    }
};

/*


[0, 5] [4, 9] [5, 10] [9, 18] [10, 18] [12,18] [15, 20] [18, 24] [20, 24]
                                                                 --------
                                                                                    

*/