class Solution {
public:
    int totalNQueens(int n) 
    {
	    vector<bool> col(n), d1(2*n-1), d2(2*n-1);
	    return solve(col, d1, d2, 0);
    }
   
    int solve(vector<bool>& col, vector<bool>& d1, vector<bool>& d2, int row) 
    {
	    int n = size(col), count = 0;
        if(row == n) return 1;
	    
        for(int column = 0; column < n; column++)
        {
            if(!col[column] && !d1[row + column] && !d2[row - column + n - 1])
            { 
			    col[column] = d1[row + column] = d2[row - column + n - 1] = true;
			    count += solve(col, d1, d2, row + 1);
			    col[column] = d1[row + column] = d2[row - column + n - 1] = false;
		    }  
        }
	    return count;
    }
};

/*

rows = 0, 1, 2
column = 1, 3, 0
diagonal = 1, 4, 2 

- Q - -
- - - Q
Q - - -
- - Q -


*/