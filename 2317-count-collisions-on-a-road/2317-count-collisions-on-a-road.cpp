class Solution {
public:
    int countCollisions(string directions) 
    {
        int n = directions.length(), cnt = 0, right = 0;
        bool isLeftBlock = false; 
        for(int i = 0; i < n; i++)
        {
            if(directions[i] == 'S') {
                cnt += right;
                right = 0;

                isLeftBlock = true;
            }
            if(directions[i] == 'R') right++;
            if(directions[i] == 'L') 
            {
                if(right != 0) 
                {
                    cnt += right + 1;
                    isLeftBlock = true;

                    right = 0;
                }
                else if(isLeftBlock) cnt += 1;
            }
        }

        return cnt;
    }
};

/*

"RLSLSLRLSLSLLR"


"SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR"

*/