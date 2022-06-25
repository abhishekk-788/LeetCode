#define ll long long
#define M 1000000007
class Solution {
public:
    ll power(ll x, ll n)
    {
        ll result = 1;
        while(n > 0)
        {
                if(n % 2 == 1) {
                    result = (result * x) % M;
                }
                x = (x * x) % M ;
                n = n / 2;
        }
        return result;
    }
    int numSubseq(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        ll s = 0;
        for(int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            if(nums[i] * 2 > target) break;
            
            int l = i+1, r = n-1, ans = i;
            while(l <= r)
            {
                int m = l + (r-l)/2;
                if(nums[m] > x) {
                    r = m - 1;
                }
                else 
                {
                    ans = m;
                    l = m + 1;
                }
            }
            
            ll p = power(2LL, ans-i);
            s = (s + p) % M;
        }
        
        return s;
    }
};

/*

3 5 6 7
      
[] -->  [7]  --> [7, 6]  --> [7, 6, 5]
                             [7, 6]
                 [7]     --> [7, 5]
                             [7]  
        []   --> [6]     --> [6, 5]
                             [6]
                 []      --> [5]
                             []
                    
3 5 6 7
3  --> 6  (3 3) (3 5) (3 6) (3 5 6)

5  6
5, 6, 5 6

5 6 7
5, 6, 7, 5 6, 5 7, 6 7, 5 6 7  

3
3 5
3 5 6
3 6
                                
*/