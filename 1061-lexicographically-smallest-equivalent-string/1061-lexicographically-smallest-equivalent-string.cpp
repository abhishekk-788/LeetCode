#define ll long long
class Solution {
public:
    ll par[26];
    void make_set() 
    {
        for(int i = 0; i < 26; i++) {
            par[i] = i;
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
            if (a > b) swap(a, b);
            par[b] = a;
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        make_set();
        int l = s1.length(), len = baseStr.length();
        for(int i = 0; i < l; i++) {
            union_set(s1[i]-'a', s2[i]-'a');
        }
        
        for(int i = 0; i < 26; i++) {
            cout << par[i] << " ";
        }
        cout << "\n";
        
        string str = "";
        for(auto ch: baseStr) 
        {
            ll f = find_set(ch-'a');
            str += char(f + 'a'); 
        }
        
        return str;
    }
};

/*



*/