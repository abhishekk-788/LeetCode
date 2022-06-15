class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();
        vector<vector<int>> vec(3);
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a') vec[0].push_back(i);
            if(s[i] == 'b') vec[1].push_back(i);
            if(s[i] == 'c') vec[2].push_back(i);
        }
        
        vec[0].push_back(n);
        vec[1].push_back(n);
        vec[2].push_back(n);
        
        int ans = 0, a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++)
        {
            // cout << vec[0][a] << " " << vec[1][b] << " " << vec[2][c] << "\n";
            
            int mx = max(vec[0][a], max(vec[1][b], vec[2][c]));
            ans += n - mx;
            
            if(s[i] == 'a') a++;
            if(s[i] == 'b') b++;
            if(s[i] == 'c') c++;
            
        }
        
        return ans;
    }
};