class Solution {
    public int countCollisions(String directions) 
    {
        int n = directions.length(), cnt = 0, right = 0;
        boolean isLeftBlock = false; 
        
        for(int i = 0; i < n; i++)
        {
            if(directions.charAt(i) == 'S') {
                cnt += right;
                right = 0;

                isLeftBlock = true;
            }
            if(directions.charAt(i) == 'R') right++;
            if(directions.charAt(i) == 'L') 
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
}

/*

RLRSLL

LSR
*/