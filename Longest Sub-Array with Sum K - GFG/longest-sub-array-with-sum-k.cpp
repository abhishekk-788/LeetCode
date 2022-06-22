// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[], int N, int K) 
    { 
        unordered_map<int, int> mp;
        
        int s = 0, ans = 0;
        
        mp[0] = -1;
        for(int i = 0; i < N; i++)
        {
            s += A[i];
            if(mp.count(s-K) == 1) {
                ans = max(ans, i - mp[s-K]);
            }
            
            if(mp.count(s) == 0) {
                mp[s] = i;
            }
        }
        
        return ans;
    } 

};

/*

1 4 3 3  5  5
1 5 8 11 16 21

2 -5 3 6 -9 -4  1 -3
2 -3 0 6 -3 -7 -6 -9

*/

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends