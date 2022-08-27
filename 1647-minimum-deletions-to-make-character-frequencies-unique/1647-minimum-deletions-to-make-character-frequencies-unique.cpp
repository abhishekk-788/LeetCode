class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> arr(26);
        
        int l = s.length(), ans = 0;
        for(int i = 0; i < l; i++) {
            arr[s[i]-97]++;
        }
        
        set<int> st;
        for(int i = 0; i < 26; i++)
        {
            while(arr[i] != 0 && st.count(arr[i]) == 1) {
                arr[i]--;  ans++;
            }
            if(arr[i] != 0) st.insert(arr[i]);
        }
        
        return ans;
    }
};

/*

3 3 2
3 

abcd
a

*/