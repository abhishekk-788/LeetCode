class Solution {
private:
    vector<int> par, rank;
    
    void init(int n) 
    {
        par.resize(n+1, 0);
        rank.resize(n+1, 0);
        
        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    int findParent(int x) 
    {
        if(x == par[x]) return x;
        return par[x] = findParent(par[x]);
    }
    
    void unionSet(int x, int y) 
    {
        int px = findParent(x);
        int py = findParent(y);
        
        if(px == py) return;
        
        if(rank[px] < rank[py]) {
            par[px] = py;
        }
        else if(rank[py] < rank[px]) {
            par[py] = px;
        }
        else {
            par[py] = px;
            rank[px]++;
        }
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        init(n);
        
        int e = edgeList.size(), q = queries.size();
        vector<bool> res(q, false);

        for (int i = 0; i < q; i++) {
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int i = 0;
        for (auto& query : queries) {
            int u = query[0], v = query[1], limit = query[2], idx = query[3];
            
            while (i < e && edgeList[i][2] < limit) {
                unionSet(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            
            if (findParent(u) == findParent(v)) {
                res[idx] = true;
            }
        }

        return res;
    }
};

/*

[0,1,2],[0,1,16],[0,2,8],[1,2,4]

[0,1,2] [0,2,5]

*/