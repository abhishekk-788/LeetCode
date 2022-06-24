class Solution {
public:
    int maxProduct(vector<int>& A) 
    {
        int r = A[0], imax = A[0], imin = A[0], n = A.size();
        for (int i = 1; i < n; i++) 
        {
            if (A[i] < 0) {
                swap(imax, imin);
            }
            
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            r = max(r, imax);
        }
        return r;
    }
};

/*

       2 3 -2  4
imax   2 6 -12 4 
imin   2 6 -12 -12

*/