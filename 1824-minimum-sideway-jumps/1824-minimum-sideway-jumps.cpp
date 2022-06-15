class Solution {
public:
    int minSideJumps(vector<int>& obs) 
    {
        int a = 1, b = 0, c = 1, n = obs.size();
        for(int i = 1; i < n-1; i++)
        {
            if(obs[i] == 1) 
            {
                a = INT_MAX;
                
                if(obs[i-1] == 2) b = c+1;   
                if(obs[i-1] == 3) c = b+1;
            }
            else if(obs[i] == 2) {
                b = INT_MAX;
                
                if(obs[i-1] == 1) a = c+1;
                if(obs[i-1] == 3) c = a+1;                
            }
            else if(obs[i] == 3) {
                c = INT_MAX;
                
                if(obs[i-1] == 1) a = b+1;
                if(obs[i-1] == 2) b = a+1;
            }
            else {
                if(obs[i-1] == 1) a = min(b+1, c+1);
                if(obs[i-1] == 2) b = min(a+1, c+1);
                if(obs[i-1] == 3) c = min(a+1, b+1);
            }
        }
        
        return min(a, min(b, c));
    }
};

/*

1 2 3 0


1 * 2 2
0 0 * 3
1 1 1 *

2 1 0 3 0

1 1 * 2 2
0 * 2 2 2
1 1 1 1 *


1 2 2 3 1 0 2

1 * 2 2 2 *   5
0 0 * * 3 3 3 *
1 1 1 1 * 4 4 4

*/