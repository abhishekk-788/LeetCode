// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(vector<int> arr, int n, int s)
    {
        if(n == 0 && s == 0) return true;
        if(n == 0) return false;
        
        if(s >= arr[n-1])
        {
            return check(arr, n-1, s - arr[n-1]) || check(arr, n-1, s);
        }
        return check(arr, n-1, s);
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        dp[0][0] = true;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(i == 0) dp[i][j] = false;
                else if(j >= arr[i-1]) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends