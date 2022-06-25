// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int start = 0, end = n-1;
        while(start < end) 
        {
            while(a[end] == 2) {
                end--;
                
                if(start == end) break;
            }
            
            if(a[start] == 2) {
                swap(a[start], a[end]);
                end--;
            }
            
            start++;
        }
        
        start = 0;
        while(start < end) 
        {
            while(a[start] == 0) {
                start++;
                
                if(start == end) break;
            }
            
            if(a[end] == 0) {
                swap(a[start], a[end]);
                start++;
            }
            
            end--;
        }
    }
    
};

/*

0 2 2 2 1 2
        


0 0 1 2 2

0 2 1 2 0 1 2 2
0 1 1 2 0 2 2 2

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