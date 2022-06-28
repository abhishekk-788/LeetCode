// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int cnt = 1, idx = 0;
        for(int i = 0; i < size; i++)
        {
            if(a[i] == a[idx]) cnt++;
            else 
            {
                cnt--;
                
                if(cnt == 0)
                {
                    idx = i;
                    cnt = 1;
                }
            }
        }
        
        cnt = 0;
        for(int i = 0; i < size; i++)
        {
            if(a[i] == a[idx]) cnt++;
        }
        
        return cnt > size/2 ? a[idx]: -1;
    }
};

/*

3 1 3 2 2 1 2
1 1 1 1 2 1 2

*/

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends