class Solution {
public:
    int gcd(int a, int b) 
    {
        if (b == 0) return a;
        return gcd(b, a % b); 
    }
    
    int minOperations(vector<int>& nums, vector<int>& div) 
    {
        sort(nums.begin(), nums.end());
        
        int x = div.size() == 1 ? div[0]: gcd(div[0], div[1]);
        int n = nums.size();
        
        for(int i = 2; i < div.size(); i++) {
            x = gcd(x, div[i]);
        }
        
        cout << "gcd : " << x << "\n";
        
        int ans = n;
        for(int i = 1; i <= sqrt(x); i++)
        {
            if(x % i == 0)
            {
                int l = 0, r = n-1, pos = n;
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    if(nums[mid] == i) {
                        pos = min(pos, mid);
                        r = mid-1;
                    }
                    else if(nums[mid] > i) {
                        r = mid-1;
                    }
                    else l = mid+1;
                }
                
                if(pos != n) ans = min(ans, pos);
            }
            
            if(x % i == 0)
            {
                int z = x/i;
                int l = 0, r = n-1, pos = n;
                
                while(l <= r)
                {
                    int mid = l + (r-l)/2;
                    if(nums[mid] == z) {
                        pos = min(pos, mid);
                        r = mid-1;
                    }
                    else if(nums[mid] > z) {
                        r = mid-1;
                    }
                    else l = mid+1;
                }
                
                if(pos != n) ans = min(ans, pos);
            }
        }
        
        return ans == n ? -1: ans;
    }
};