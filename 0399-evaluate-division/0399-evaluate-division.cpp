class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> G;
    void dfs(string& s,string& d , set<string>& vis, double& ans, double temp) 
    {
        if(vis.find(s) != vis.end()) { 
            return;
        } else 
        {
            vis.insert(s);
            if(s==d) 
            {   
                ans = temp;
                return;
            } else 
            {
                for(auto nbr : G[s]){ 
                    dfs(nbr.first, d, vis, ans, temp * nbr.second);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        for(int i = 0; i < equations.size(); i++) {
            G[equations[i][0]].push_back({equations[i][1],values[i]}); 
            G[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }

        vector<double> res(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            string s = queries[i][0];
            string d = queries[i][1];
            set<string> vis;
            double ans = -1.0;
            if(G.find(s) != G.end()) 
                dfs(s,d,vis,ans,1.0); 
            
            res[i] = ans; 
        }
        return res;
    }
};

/*

a/b = 2
b/c = 3

a -> b = 2
b -> a = 0.5
b -> c = 3
c -> b = 1/3



*/