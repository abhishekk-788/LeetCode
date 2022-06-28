// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) 
	{
	    long long pos = arr[0], ans = arr[0], neg = arr[0];
	    for(int i = 1; i < n; i++)
	    {
	        if(arr[i] < 0) {
	            swap(pos, neg);
	        }
	        
	        pos = max(arr[i] * 1LL, pos * 1LL * arr[i]);
	        neg = min(arr[i] * 1LL, neg * 1LL * arr[i]);
	        
	        ans = max(ans, pos);
	    }
	    return ans;
	}
};

/*

int x = 6;
int y = -3

7
9 0 8 -1 -2 -2 6

9 0 8 -8 16
9 0 0 8

9 9 9 


p = 1 9 1 8 16 4
n = -1 -2 -32

- +  (-) Ans
+ -  



*/

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends