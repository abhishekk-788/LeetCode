// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int sum = 0, end = 0, start = 0;
        while(end < n)
        {
            if(sum < s) {
                sum += arr[end];
            }
            if(sum > s)
            {
                while(sum > s)
                {
                    sum -= arr[start];
                    start++;
                }
            }
            if(sum == s) return {start+1, end+1};
            end++;
        }
        
        return {-1};
    }
};

/*

1 3 6 13 18
1 2 3 

*/

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends