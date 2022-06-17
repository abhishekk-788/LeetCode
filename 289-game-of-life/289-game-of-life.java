class Solution {
    private static final int[][] DIRS = {{ 0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    public void gameOfLife(int[][] board) 
    {
        if (board == null || board.length == 0 || board[0].length == 0) return;

        int rows = board.length;
        int cols = board[0].length;

        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                int liveCount = 0;
                for (int[] d : DIRS) 
                {
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x >= 0 && x < rows && y >= 0 && y < cols) 
                    {
                        liveCount += board[x][y] & 1;
                    }
                }
                if(liveCount == 3 || (board[i][j] == 1 && liveCount == 2)) {
                    board[i][j] |= 2; 
                }
            }
        }
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                System.out.print(board[i][j] + " ");
                board[i][j] /= 2;
            }
            System.out.println();
        }
    }
}

/*

0 1 0 
2 0 3 
1 3 3 
0 2 0 

*/