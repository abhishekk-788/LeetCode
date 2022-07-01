class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        queue<int>q;
        for(int i=1;i<=n;i++) {
            q.push(i);
        }
        int i=0;
        while(q.size()!=1)
        {
            i++;
            int t=q.front();
            
            if(i==k) {
                q.pop();
                i=0;
            }
            else
            {
                q.pop();
                q.push(t);
            }
        }
        
        return q.front();
    }
};

/*

1 2 4 5 7 8  k = 3

2 3 5 7



n+2

*/