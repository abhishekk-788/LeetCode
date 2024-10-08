// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        long long s = 0, m = 1e9+7;
        for(long long i = 0; i < n; i++)
        {
            long long x = a[i] * (i+1) * (n-i);
            x = x % m;
            
            s = (s + x) % m;
        }
        
        return s;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends