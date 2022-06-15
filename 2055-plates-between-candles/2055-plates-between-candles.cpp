class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) 
    {
        int n = s.length(), p = 0, c = 0, q = queries.size();
        vector<int> plt(n), cndl(n), ans;
        
        int cndli[100005];
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*') p++;
            if(s[i] == '|') 
            {
                c++;
                cndli[c] = i;
                
                cout << c << " " << cndli[c] << "   ";
            }
            
            plt[i] = p; cndl[i] = c;
        }
        
        cndli[0] = cndli[1];
        
        for(int i = 0; i < q; i++) 
        {
            int x = queries[i][0], y = queries[i][1];
            
            int l1 = cndl[x], l = (cndli[l1] == x) ? cndli[l1]: cndli[l1+1];
            int r1 = cndl[y], r = cndli[r1];
            
            if(l >= r) ans.push_back(0);
            else ans.push_back(plt[r]-plt[l]);
        }
        
        return ans;
    }
};

/*

**|**|***|
0123456789
1223445677
0011122223
  1  2
  
||||**|||||||*||*||*||**|*
  
0112345556789012234456678889900122
*|*||||**|||||||*||*||*||**|*|*||*
0123456789012345678901234567890123

3 28

*/