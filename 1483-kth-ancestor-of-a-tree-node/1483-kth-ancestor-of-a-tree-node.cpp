class TreeAncestor {
public:
    int ancestors[50005][20];
    TreeAncestor(int n, vector<int>& parent) 
    {
         memset(ancestors, -1, sizeof(ancestors));

        for (int node = 0; node < n; ++node) {
            ancestors[node][0] = parent[node];
        }

        for (int i = 1; i < 20; i++) 
        {
            for (int node = 0; node < n; node++) 
            {
                int prevAncestor = ancestors[node][i - 1];
                if (prevAncestor != -1) {
                    ancestors[node][i] = ancestors[prevAncestor][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20 && node != -1; ++i) 
        {
            if (k & (1 << i)) {
                node = ancestors[node][i];
            }
        }
        return node;
    }
};

/*

0 -> 1 -> 2
1 -> 3 -> 4
2 -> 5 -> 6


6 -> 2
5 -> 2
4 -> 1
3 -> 1
1 -> 0
2 -> 0

dp[node][level] = parent;

*/

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */