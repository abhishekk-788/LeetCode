class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int n = customers.size(), s = 0, ts = 0;
        vector<int> csg(n), tsg(n);
        
        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0) s += customers[i];
            ts += customers[i];
            
            csg[i] = s; tsg[i] = ts;
        }
        
        if(minutes == n) return ts;
        
        int x = tsg[minutes-1] + (s - csg[minutes-1]), ans = x;
        for(int i = 1; i <= n-minutes; i++)
        {
            x = tsg[i+minutes-1] - tsg[i-1] + (s - csg[i+minutes-1] + csg[i-1]);
            ans = max(ans, x);
        }
        
        ans = max(ans, x);
        
        return ans;
    }
};

/*

[1,0,1,2,1,1,7,5]
[0,1,0,1,0,1,0,1]



0 1 2 3 4 5 6  7
1 1 2 2 3 3 10 10  -- csg
1 1 2 4 5 6 13 18  -- tsg

5 - 1 + 10 - 3 + 1 = 12

0  1  2
4 10 10
1  1  0

4 14 14
4 14 24


*/