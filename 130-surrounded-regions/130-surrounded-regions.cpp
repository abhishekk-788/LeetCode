class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        if(i < 0 || i == n || j < 0 || j == m || board[i][j] != 'O') return;
        board[i][j] = 'Y';
        
        dfs(board, i+1, j, n, m);
        dfs(board, i-1, j, n, m);
        dfs(board, i, j+1, n, m);
        dfs(board, i, j-1, n, m);
        
    }
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && board[i][j] == 'O') dfs(board, i, j, n, m);
                else if(i == n-1 && board[i][j] == 'O') dfs(board, i, j, n, m);
                else if(j == 0 && board[i][j] == 'O') dfs(board, i, j, n, m);
                else if(j == m-1 && board[i][j] == 'O') dfs(board, i, j, n, m);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};