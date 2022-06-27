#define ll long long
class Solution {
public:
    ll par[100005], size[100005];
    void make_set() 
    {
        for(int i = 0; i < 100000; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    ll find_set(ll v) 
    {
        if (v == par[v]) return v;
        return par[v] = find_set(par[v]);
    }

    void union_set(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);

        if (a != b) 
        {
            if (size[a] < size[b]) swap(a, b);

            par[b] = a;
            size[a]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int m = isConnected.size(), n = isConnected[0].size();
        make_set();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j]) {
                    union_set(i, j);
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(par[i] == i) cnt++;
        }
        
        return cnt;
    }
};

/*

 [1,1,0]
 [1,1,0]
 [0,0,1]

*/