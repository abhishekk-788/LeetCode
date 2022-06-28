// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n)
    {
        int i = 0, curr = arr[i], jumps = 0, mx_curr = arr[i];
        
        if(n == 1) return 0;
        if(arr[0] >= n-1) return 1;
        
        while(1)
        {
            mx_curr = max(mx_curr, i+arr[i]);
            if(i == curr)
            {
                jumps++;
                curr = mx_curr;
                
                if(curr >= n-1) return jumps+1;
                if(curr == i) break;
            }
            i++;
        }
        
        return -1;
    }
};

/*

11
0 1 2 3 4 5 6 7 8 9 0
1 3 5 8 9 2 6 7 6 8 9

*/


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends