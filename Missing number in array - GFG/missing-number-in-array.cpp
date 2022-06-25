// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) 
    {
        long long sum = n * 1LL * (n+1) / 2, s = 0;
        for(int i = 0; i < array.size(); i++)
        {
            s += array[i];
        }
        
        return sum - s;
    }
};

/*

1 2 3 5 = 11
1 2 3 4 5 = 15

15 - 11

*/

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends