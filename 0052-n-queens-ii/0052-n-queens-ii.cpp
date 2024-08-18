class Solution {
public:
    int count;
    bool checkValid(vector<string> &board, int row, int col, int size) 
    {
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        
        for(int i = 1; i <= row; i++)
        {
            if(col-i >= 0) {
                if(board[row-i][col-i] == 'Q'){
                    return false;
                }
            }
            if(col+i < size){
                if(board[row-i][col+i] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }

    void helper(vector<string> &board, int row, int size)
    {
        if(row == size){
            count++;
            return;
        }
        for(int i = 0; i<size; i++)
        {
            if(checkValid(board, row, i, size)){
                board[row][i] = 'Q';
                helper(board, row+1, size);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) 
    {
        string str;
        str.append(n, '.');
        vector<string> board(n, str);
        
        count = 0;
        
        helper(board, 0, n);
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