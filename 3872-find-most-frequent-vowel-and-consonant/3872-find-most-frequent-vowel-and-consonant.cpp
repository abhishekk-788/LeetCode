class Solution {
public:
    int maxFreqSum(string s) 
    {
        vector<int> arr(26, 0);
        for(int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
        }

        int mxv = 0, mxc = 0;
        for(int i = 0; i < 26; i++) {
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
                mxv = max(mxv, arr[i]);
            }
            else mxc = max(mxc, arr[i]);
        }

        cout << mxv << " " << mxc << "\n";
        return mxv+mxc;
    }
};