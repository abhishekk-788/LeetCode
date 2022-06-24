class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        if(n == 1) return 1;
        
        int x = 1, y = 1, ans = arr[1] == arr[0] ? 1: 2;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] > arr[i-1] && i % 2 == 1) {
                x = x + 1;
                y = 1;
            } 
            else if(arr[i] < arr[i-1] && i % 2 == 0) {
                x = x + 1;
                y = 1;
            } 
            else if(arr[i] > arr[i-1] && i % 2 == 0) {
                y = y + 1;
                x = 1;
            } 
            else if(arr[i] < arr[i-1] && i % 2 == 1) {
                y = y + 1;
                x = 1;
            } 
            else {
                x = 1;
                y = 1;
            }
            
            // cout << x << " " << y << "\n";
            ans = max(ans, max(x, y));
        }
        
        return ans;
    }
};

/*


*/