class Solution {
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> jump(n+1);
        
        for(int i = 0; i <= n; i++)
        {
            int x = max(0, i - ranges[i]);
            int y = min(n, i + ranges[i]);
            
            jump[x] = max(jump[x], y-x);
        }
        
        for(auto x: jump) {
            cout << x << " ";
        }
        
        int count = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i<jump.size()-1; i++) 
        {
            if (i>curFarthest)
                return -1;
            
            curFarthest = max(curFarthest, i + jump[i]);
            
            if (i == curEnd) 
            {
                count++;
                curEnd = curFarthest;
            }
        }
        
        return curFarthest >= n ? count : -1;
        
        return 0;
    }
};