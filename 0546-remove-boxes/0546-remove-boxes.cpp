class Solution {
public:
    int dp[100][100][100];
    int removeBoxes(vector<int>& boxes)
    {
        memset(dp, -1, sizeof(dp));
        return operate(boxes, 0, boxes.size()-1, 0);
    }

    int operate(vector<int>& boxes, int i, int j, int k)
    {
        if (i>j) return 0;
        if (dp[i][j][k]>0) return dp[i][j][k];

        int res = (k+1)*(k+1) + operate(boxes, i+1, j, 0);
        for (int m=i+1; m<=j; m++)
        {

            if (boxes[i]==boxes[m])
                res = max( res, operate(boxes, i+1, m-1, 0)+operate(boxes, m, j, k+1));
        }
        dp[i][j][k] = res;
        return res;
    }
};