class Solution {
    int[] par, rank;
    int findPar(int x) {
        if(x == par[x]) return x;
        return par[x] = findPar(par[x]);
    }
    void union(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;
        if(rank[pu] < rank[pv]) {
            par[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            par[pv] = pu;
        }
        else {
            par[pv] = pu;
            rank[pu]++;
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        
        par = new int[n+1];
        rank = new int[n+1];

        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && isConnected[i][j] == 1){
                    union(i, j);
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
}

/*

1 1 0
1 1 0
0 0 1

*/