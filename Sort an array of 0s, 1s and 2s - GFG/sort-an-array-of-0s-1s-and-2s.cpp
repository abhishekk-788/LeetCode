// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
         int cnt1 = 0, cnt2 = 0;
         for(int i = 0; i < n; i++)
         {
             if(a[i] == 0) cnt1++;
             if(a[i] == 2) cnt2++;
         }
         
         for(int i = 0; i < n; i++)
         {
             if(i < cnt1) a[i] = 0;
             else if(n-i-1 < cnt2) a[i] = 2;
             else a[i] = 1;
         }
    }
    
};

/*


0 2 1 2 0
0 0 1 

0 2 1 2 0 1 2 2
0 0

*/

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends