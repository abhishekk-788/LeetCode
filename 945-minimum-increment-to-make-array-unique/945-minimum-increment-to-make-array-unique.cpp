class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        queue<int> q;
        
        int k = nums[0], ans = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) {
                q.push(nums[i]);
            }
            else 
            {
                while(!q.empty() && nums[i] - k != 1)
                {
                    ans += (k - q.front() + 1);
                    k++;
                    
                    // cout << q.front() << " " << k << " " << i << " " << nums[i] << " " << ans << "\n";

                    q.pop();
                }
            }
            
            k = nums[i];
        }
        
        while(!q.empty()) 
        {
            ans += k-q.front()+1;
            k++;
            
            q.pop();
        }
        
        return ans;
    }
};

/*

3 2 1 2 1 7
1 1 2 2 3 7

1 2 2 3 4 5 6 7 8 9

1 1 1 1 2 2 2 6 7 8
1 2 3 4 5 6 7 8 9 10

0 1 2 3 3 4 5 2 2 2 = 24

*/