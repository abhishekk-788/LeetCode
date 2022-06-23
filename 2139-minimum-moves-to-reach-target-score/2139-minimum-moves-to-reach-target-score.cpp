class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int cnt = 0;
        while(maxDoubles != 0 && target != 1)
        {
            if(target % 2 == 1) target--;
            else 
            {
                target /= 2;
                maxDoubles--;
            }
            cnt++;
            
            // cout << target << " " << cnt << "\n";
        }
        
        cnt += target-1;
        return cnt;
    }
};